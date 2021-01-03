import struct
import socket

_MAX_STR_LEN = 255
_MAX_BYTES_LEN = 1024 * 1024 * 10

_SAVE_FILE_OP = 100
_READ_FILE_OP = 200
_DELETE_FILE_OP = 201
_GET_ALL_FILENAMES_OP = 202

_SAVE_FILE_SUCCESS_STATUS = 212
_READ_FILE_SUCCESS_STATUS = 210
_DELETE_FILE_SUCCESS_STATUS = 212
_GET_ALL_FILENAMES_SUCCESS_STATUS = 211

_FILE_NOT_FOUND_FAILURE_STATUS = 1001
_NO_FILES_ON_SERVER_FAILURE_STATUS = 1002
_GENERAL_FAILURE_STATUS = 1003


class _SockHelper:
    def __init__(self, sock: socket.socket):
        self.sock = sock

    def read_byte(self):
        data = self.__read_binary(1)
        return struct.Struct('< B').unpack(data)[0]

    def write_byte(self, data):
        data = struct.Struct('< B').pack(data)
        self.__write_binary(data)

    def read_short(self):
        data = self.__read_binary(2)
        return struct.Struct('< H').unpack(data)[0]

    def write_short(self, data):
        data = struct.Struct('< H').pack(data)
        self.__write_binary(data)

    def read_int(self):
        data = self.__read_binary(4)
        return struct.Struct('< I').unpack(data)[0]

    def write_int(self, data):
        data = struct.Struct('< I').pack(data)
        self.__write_binary(data)

    def read_str(self):
        size = self.read_short()

        if size > _MAX_STR_LEN:
            raise Exception("Str len is bigger than the maximum allowed")

        data = self.__read_binary(size)
        return str(struct.Struct('{0}s'.format(size)).unpack(data)[0], encoding="UTF-8")

    def write_str(self, string):
        data_raw = bytes(string, encoding="UTF-8")
        data = struct.Struct('{0}s'.format(len(data_raw))).pack(data_raw)
        self.write_short(len(data_raw))
        self.__write_binary(data)

    def read_bytes(self):
        size = self.read_int()

        if size > _MAX_BYTES_LEN:
            raise Exception("Payload len is bigger than the maximum allowed")

        return self.__read_binary(size)

    def write_bytes(self, data):
        self.write_int(len(data))
        self.__write_binary(data)

    def __read_binary(self, length):
        result = bytes()
        amount_read = 0
        while amount_read < length:
            data = self.sock.recv(length - amount_read)
            if data is None or len(data) == 0:
                raise Exception("Socket closed")
            amount_read = amount_read + len(data)
            result = result + data
        return result

    def __write_binary(self, data):
        self.sock.send(data)


class Request:

    def __init__(self, user_id, version, op, file_name: str = None, payload=None):
        self.user_id = user_id
        self.version = version
        self.op = op
        self.file_name = file_name
        self.payload = payload

    def __str__(self) -> str:
        return "userId={0}, version={1}, op={2}, filename={3}".format(self.user_id, self.version, self.op,
                                                                      self.file_name)

    def send(self, sock):
        helper = _SockHelper(sock)
        helper.write_int(self.user_id)
        helper.write_byte(self.version)
        helper.write_byte(self.op)

        if self.file_name is not None:
            helper.write_str(self.file_name)

        if self.payload is not None:
            helper.write_bytes(self.payload)


class Response:
    def __init__(self, sock):
        helper = _SockHelper(sock)
        self.version = helper.read_byte()
        self.status = helper.read_short()
        self.file_name = None

        if self.status < 1002:
            self.file_name = helper.read_str()

        if self.status < 212:
            self.payload = helper.read_bytes()

    def __str__(self) -> str:
        return "version={0}, status={1}, filename={2}".format(self.version, self.status, self.file_name)


class _ServerCommManagerHelper:

    def __init__(self, host, port):
        self.host = host
        self.port = port

    def send_request_and_get_response(self, request: Request):
        print("Opening connection to: {0}:{1}".format(self.host, self.port))
        with socket.create_connection((self.host, self.port)) as sock:
            print("Sending request: {}".format(request))
            request.send(sock)
            resp = Response(sock)
            print("Got response: {}".format(resp))
            return resp


class ServerCommManager:
    def __init__(self, host, port, user_id):
        self.host = host
        self.port = port
        self.used_id = user_id
        self.comm_helper = _ServerCommManagerHelper(self.host, self.port)

    def send_file(self, file_name):
        with open(file_name, "rb") as file:
            data = bytes(file.read())
            req = Request(self.used_id, 0, _SAVE_FILE_OP, file_name, data)
            resp = self.comm_helper.send_request_and_get_response(req)

            if resp.status != _SAVE_FILE_SUCCESS_STATUS:
                raise Exception("File save operation failed with status code = {}".format(resp.status))

    def read_file(self, file_name, destination_file_name):
        req = Request(self.used_id, 0, _READ_FILE_OP, file_name)
        resp = self.comm_helper.send_request_and_get_response(req)
        if resp.status == _READ_FILE_SUCCESS_STATUS:
            with open(destination_file_name, "rb") as file:
                file.write(resp.payload)
        elif resp.status == _FILE_NOT_FOUND_FAILURE_STATUS:
            raise Exception("File not found error")
        else:
            raise Exception("File read operation failed with status code = {}".format(resp.status))

    def delete_file(self, file_name):
        req = Request(self.used_id, 0, _DELETE_FILE_OP, file_name)
        resp = self.comm_helper.send_request_and_get_response(req)
        if resp.status == _DELETE_FILE_SUCCESS_STATUS:
            pass
        elif resp.status == _FILE_NOT_FOUND_FAILURE_STATUS:
            raise Exception("File not found error")
        else:
            raise Exception("File read operation failed with status code = {}".format(resp.status))

    def list_all_files(self):
        req = Request(self.used_id, 0, _GET_ALL_FILENAMES_OP)
        resp = self.comm_helper.send_request_and_get_response(req)
        if resp.status == _GET_ALL_FILENAMES_SUCCESS_STATUS:
            files = str(resp.payload, encoding="UTF-8").split("\n")
            return [file for file in files if len(file) > 0]
        elif resp.status == _NO_FILES_ON_SERVER_FAILURE_STATUS:
            raise Exception("No files for user on server")
        else:
            raise Exception("Get all files operation failed with status code = {}".format(resp.status))


if __name__ == '__main__':
    server = ServerCommManager("127.0.0.1", 1234, 1234)
    all_files = server.delete_file(".gitignore")
    print(all_files)

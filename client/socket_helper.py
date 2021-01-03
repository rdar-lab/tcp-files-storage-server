import os
import socket
import struct

_MAX_STR_LEN = 255
_MAX_BYTES_LEN = 1024 * 1024 * 10

_BUFFER_SIZE = 1000


class SockHelper:
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

    def send_file(self, file_name):
        file_size = os.path.getsize(file_name)

        print("Sending file {1} which is of size {0}".format(file_size, file_name))

        self.write_int(file_size)

        with open(file_name, "rb") as file:
            while True:
                piece = file.read(_BUFFER_SIZE)
                if not piece:
                    break
                self.__write_binary(piece)

    def receive_file(self, file_name):
        size = self.read_int()
        amount_left = size

        if size > _MAX_BYTES_LEN:
            raise Exception("Payload len is bigger than the maximum allowed")

        print("Receiving file of size {0}, and storing at {1}".format(size, file_name))

        with open(file_name, "wb") as file:
            while amount_left > 0:
                amount_to_read = amount_left
                if amount_to_read > _BUFFER_SIZE:
                    amount_to_read = _BUFFER_SIZE
                data = self.__read_binary(amount_to_read)
                file.write(data)
                amount_left = amount_left - amount_to_read

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

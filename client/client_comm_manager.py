import socket
from request import Request
from response import Response

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


class _ServerCommManagerHelper:
    #
    # Helper class for the communication, sends the requests and get the responses
    #

    def __init__(self, host, port):
        self.host = host
        self.port = port

    def send_request_and_get_response(self, request: Request):
        #
        # Sends the request and gets back the response
        #
        print("Opening connection to: {0}:{1}".format(self.host, self.port))
        with socket.create_connection((self.host, self.port)) as sock:
            print("Sending request: {}".format(request))
            request.send(sock)
            resp = Response(sock)
            print("Got response: {}".format(resp))
            return resp


class ClientCommManager:
    #
    # The client communication manager
    #

    def __init__(self, host, port, user_id):
        self.host = host
        self.port = port
        self.used_id = user_id
        self.comm_helper = _ServerCommManagerHelper(self.host, self.port)

    def send_file(self, file_name):
        #
        # Sends the file to the server
        #

        req = Request(self.used_id, 0, _SAVE_FILE_OP, file_name, True)
        resp = self.comm_helper.send_request_and_get_response(req)

        if resp.status != _SAVE_FILE_SUCCESS_STATUS:
            raise Exception("File save operation failed with status code = {}".format(resp.status))

    def read_file(self, file_name):
        #
        # Reads the file from the server
        #

        req = Request(self.used_id, 0, _READ_FILE_OP, file_name)
        resp = self.comm_helper.send_request_and_get_response(req)
        if resp.status == _READ_FILE_SUCCESS_STATUS:
            return resp.storage_file
        elif resp.status == _FILE_NOT_FOUND_FAILURE_STATUS:
            raise Exception("File not found error")
        else:
            raise Exception("File read operation failed with status code = {}".format(resp.status))

    def delete_file(self, file_name):
        #
        # Delete the file
        #

        req = Request(self.used_id, 0, _DELETE_FILE_OP, file_name)
        resp = self.comm_helper.send_request_and_get_response(req)
        if resp.status == _DELETE_FILE_SUCCESS_STATUS:
            pass
        elif resp.status == _FILE_NOT_FOUND_FAILURE_STATUS:
            raise Exception("File not found error")
        else:
            raise Exception("File read operation failed with status code = {}".format(resp.status))

    def list_all_files(self):
        #
        # List all files
        #

        req = Request(self.used_id, 0, _GET_ALL_FILENAMES_OP)
        resp = self.comm_helper.send_request_and_get_response(req)
        if resp.status == _GET_ALL_FILENAMES_SUCCESS_STATUS:
            with open(resp.storage_file, "rb") as file:
                payload = file.read()
                files = str(payload, encoding="UTF-8").split("\n")
                return [file for file in files if len(file) > 0]
        elif resp.status == _NO_FILES_ON_SERVER_FAILURE_STATUS:
            raise Exception("No files for user on server")
        else:
            raise Exception("Get all files operation failed with status code = {}".format(resp.status))

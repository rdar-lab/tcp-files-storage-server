from uuid import uuid4

from socket_helper import SockHelper


class Response:
    #
    # Response object that can read the response from the socket and return the fields:
    # "version, status, file_name"
    # Also, if the server sends a file, a temp file will be created on the client side
    #
    def __init__(self, sock):
        helper = SockHelper(sock)
        self.version = helper.read_byte()
        self.status = helper.read_short()
        self.file_name = None

        if self.status < 1002:
            self.file_name = helper.read_str()

        if self.status < 212:
            self.validate_file_name()
            tmp_file_name = '{0}.{1}'.format(self.file_name, uuid4())
            helper.receive_file(tmp_file_name)
            self.storage_file = tmp_file_name

    def __str__(self) -> str:
        return "version={0}, status={1}, filename={2}".format(self.version, self.status, self.file_name)

    def validate_file_name(self):
        #
        # Validate the file name and make sure it does not contain invalid chars
        # that can be used to attack the client
        #
        self.file_name = self.file_name.strip()

        if len(self.file_name):
            raise Exception("File name is empty")

        if '..' in self.file_name or \
                '/' in self.file_name or \
                '\\' in self.file_name or \
                '*' in self.file_name:
            raise Exception("Invalid chars detected in file_name")

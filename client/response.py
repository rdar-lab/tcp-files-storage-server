from uuid import uuid4

from socket_helper import SockHelper


class Response:
    def __init__(self, sock):
        helper = SockHelper(sock)
        self.version = helper.read_byte()
        self.status = helper.read_short()
        self.file_name = None

        if self.status < 1002:
            self.file_name = helper.read_str()

        if self.status < 212:
            tmp_file_name = '{0}.{1}'.format(self.file_name, uuid4())
            helper.receive_file(tmp_file_name)
            self.storage_file = tmp_file_name

    def __str__(self) -> str:
        return "version={0}, status={1}, filename={2}".format(self.version, self.status, self.file_name)

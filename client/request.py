from socket_helper import SockHelper


class Request:

    def __init__(self, user_id, version, op, file_name: str = None, send_file=None):
        self.user_id = user_id
        self.version = version
        self.op = op
        self.file_name = file_name
        self.send_file = send_file

    def __str__(self) -> str:
        return "userId={0}, version={1}, op={2}, filename={3}".format(self.user_id, self.version, self.op,
                                                                      self.file_name)

    def send(self, sock):
        helper = SockHelper(sock)
        helper.write_int(self.user_id)
        helper.write_byte(self.version)
        helper.write_byte(self.op)

        if self.file_name is not None:
            helper.write_str(self.file_name)

            if self.send_file:
                helper.send_file(self.file_name)

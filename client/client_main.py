import os
import random

import utils
from client_comm_manager import ClientCommManager

if __name__ == '__main__':
    user_id = random.randint(0, 2 ** 32)

    server_host, server_port = utils.read_server_config("server.info")
    file_names = utils.read_files_list("backup.info")

    client = ClientCommManager(server_host, server_port, user_id)

    try:
        print("Getting existing files list")
        existing_file_names = client.list_all_files()
        print("Existing file names: {}".format(existing_file_names))
    except Exception as ex:
        print("Error while getting existing file names: {}".format(ex))

    try:
        print("Sending the first file")
        client.send_file(file_names[0])
        print("File save was success")
    except Exception as ex:
        print("Error while saving file: {}".format(ex))

    try:
        print("Sending the second file")
        client.send_file(file_names[1])
        print("File save was success")
    except Exception as ex:
        print("Error while saving file: {}".format(ex))

    try:
        print("Getting existing files list")
        existing_file_names = client.list_all_files()
        print("Existing file names: {}".format(existing_file_names))
    except Exception as ex:
        print("Error while getting existing file names: {}".format(ex))

    try:
        print("Getting the first file")
        tmp_file_name = client.read_file(file_names[0])
        os.rename(tmp_file_name, "tmp")
        print("File read was success")
    except Exception as ex:
        print("Error while reading file: {}".format(ex))

    try:
        print("Deleting the first file")
        client.delete_file(file_names[0])
        print("File delete was success")
    except Exception as ex:
        print("Error while deleting file: {}".format(ex))

    try:
        print("Getting the first file")
        client.read_file(file_names[0])
        print("File read was success")
    except Exception as ex:
        print("Error while reading file: {}".format(ex))

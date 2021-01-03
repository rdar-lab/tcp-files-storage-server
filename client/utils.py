def read_server_config(config_file_name):
    with open(config_file_name, "rt") as file:
        line = file.readline()
        parts = line.strip().split(':')
        return parts[0], parts[1]


def read_files_list(file_list_file_name):
    file_names = []
    with open(file_list_file_name, "rt") as file:
        for line in file:
            line = line.strip()
            if len(line) > 0:
                file_names.append(line)
    return file_names

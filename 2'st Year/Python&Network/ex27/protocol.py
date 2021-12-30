#   Ex. 2.7 template - protocol
#   Author:Roei Barak,318419611

LENGTH_FIELD_SIZE = 4
PORT = 8820
ONE_PARM = 1
TWO_PARM = 2
THREE_PARM = 3

ONE_PARM_COMMAND = ["EXIT", "TAKE_SCREENSHOT", "SEND_FILE", "SEND_PHOTO"]
TWO_PARM_COMMAND = ["DIR", "DELETE", "EXECUTE"]
THREE_PARM_COMMAND = ["COPY"]


def check_cmd(data):
    """
    Check if the command is defined in the protocol, including all parameters
    For example, DELETE c:\work\file.txt is good, but DELETE alone is not
    """
    data_arg = data.split()
    command = data_arg[0]
    if (command in ONE_PARM_COMMAND) and len(data_arg) == ONE_PARM:
        return True
    if (command in TWO_PARM_COMMAND) and len(data_arg) == TWO_PARM:
        return True
    if (command in THREE_PARM_COMMAND) and len(data_arg) == THREE_PARM:
        return True
    return False


def create_msg(data):
    """
    Create a valid protocol message, with length field like 2.6
    """
    length = str(len(data))
    zfill_length = length.zfill(LENGTH_FIELD_SIZE)
    return zfill_length + data


def get_msg(my_socket):
    """
    Extract message from protocol, without the length field
    If length field does not include a number, returns False, "Error"
    """
    length = my_socket.recv(LENGTH_FIELD_SIZE).decode()
    if not length.isdigit():
        return False, "Error"
    else:
        message = my_socket.recv(int(length)).decode()
        return True, message




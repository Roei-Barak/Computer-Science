"""EX 2.6 protocol implementation
   Author:Roei Barak
   Date:
"""
import datetime
import random

LENGTH_FIELD_SIZE = 2
PORT = 8820


def check_cmd(data):
    """Check if the command is defined in the protocol (e.g RAND, NAME, TIME, EXIT)"""
    if (data == "TIME") or (data == "WHORU") or (data == "RAND") or (data == "EXIT"):
        return True
    return False


def create_msg(data):
    """Create a valid protocol message, with length field"""
    length = str(len(data))
    zfill_length = length.zfill(LENGTH_FIELD_SIZE)
    return zfill_length + data


def get_msg(my_socket):
    """Extract message from protocol, without the length field
       If length field does not include a number, returns False, "Error" """
    length = my_socket.recv(LENGTH_FIELD_SIZE).decode()
    if not length.isdigit():
        return False, "Error"
    else:
        message = my_socket.recv(int(length)).decode()
        return True, message


def create_server_rsp(cmd):
    """Based on the command, create a proper response"""

    if cmd == 'TIME':
        return str(datetime.datetime.now())
    elif cmd == 'WHORU':
        return "RoeiBarkServer"
    elif cmd == 'RAND':
        return str(random.randrange(1, 10))
    elif cmd == 'EXIT':
        return "EXIT"


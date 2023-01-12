"""
   Author: Roei Barak
   Date:
   Possible client commands:
    NAME <name> will set name. Server will reply error if duplicate
    GET_NAMES will get all names
    MSG <NAME> <message> will send message to client name
    EXIT will close client
"""

COMMANDS = ["NAME", "GET_NAMES", "MSG", "EXIT"]

LENGTH_FIELD_SIZE = 2
PORT = 8820
MAX_LEN = 99
ZERO_FILL_LEN = 11

def create_msg(data):
    length = (len(data))
    if length > MAX_LEN:
        message = "The message is to long"
        return f"{str(len(message))}{message}"
    if length < ZERO_FILL_LEN:
        zfill_length = str(length).zfill(LENGTH_FIELD_SIZE)
        message = zfill_length + data
    else:
        message = str(length) + data
    """Create a valid protocol message, with length field"""
    return f"{message}"


def get_msg(my_socket):
    length = my_socket.recv(LENGTH_FIELD_SIZE)
    if length == b'':
        return False, 'EXIT'
    message = my_socket.recv(int(length)).decode()
    """Extract message from protocol, without the length field
     If length field does not include a number, returns False, "Error" """
    return True, message

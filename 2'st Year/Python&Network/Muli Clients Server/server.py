"""
Roei Barak
318419611
Server
"""


import socket
import select
import protocol
from enum import Enum

MAX_MSG_LENGTH = 1024
SERVER_PORT = 5555
SERVER_IP = '0.0.0.0'
DIC = {}
CMD_LEN = 2


class Cmd(Enum):
    COMMAND = 0
    NAME = 1
    MESSAGE = 2


def cmd_parser(cmd):

    """Parse cmd to all 3 parts : Command , Name and Message"""
    cmd_parsed = cmd.split(' ')
    cmd_name = cmd_parsed[Cmd.COMMAND.value]
    if len(cmd_parsed) < CMD_LEN:
        return [cmd_name, '', '']
    recipient_name = cmd_parsed[Cmd.NAME.value]
    mes = ' '.join(cmd_parsed[Cmd.MESSAGE.value:])
    return [cmd_name, recipient_name, mes]


def create_server_rsp(cmd):
    """Based on the command, create a proper response"""
    parsing_cmd = cmd_parser(cmd)

    if parsing_cmd[Cmd.COMMAND.value] == 'NAME':
        # If name already exist in DIC
        if parsing_cmd[Cmd.NAME.value] in DIC:
            return protocol.create_msg("This name is already exist please choose another name!\n")
        DIC.update({parsing_cmd[Cmd.NAME.value]: current_socket})
        return protocol.create_msg("Hello " + parsing_cmd[Cmd.NAME.value])

    if parsing_cmd[Cmd.COMMAND.value] == 'GET_NAMES':
        # Give all name in DIC
        return protocol.create_msg(' '.join(DIC.keys()))

    if parsing_cmd[Cmd.COMMAND.value] == "MSG":
        # If name of recipient doesn't in DIC
        if parsing_cmd[Cmd.NAME.value] not in DIC.keys():
            return protocol.create_msg("Name doesnt exist")
        return parsing_cmd[Cmd.MESSAGE.value]

    if parsing_cmd[Cmd.COMMAND.value] == "EXIT":
        return protocol.create_msg("EXIT")

    # Default message
    return protocol.create_msg("ERROR")


def check_cmd(cmd):
    parse_cmd = cmd_parser(cmd)
    """Check if the command is defined in the protocol """
    if parse_cmd[Cmd.COMMAND.value] not in protocol.COMMANDS:
        return False
    """Check if the syntax of the command is correct"""
    if parse_cmd[Cmd.COMMAND.value] == 'MSG':
        # if MSG have wrong parameters
        if parse_cmd[Cmd.NAME.value] == '' or parse_cmd[Cmd.MESSAGE.value] == '':
            return False
    if parse_cmd[Cmd.COMMAND.value] == 'GET_NAMES':
        # if GET_NAMES have another parameters
        if parse_cmd[Cmd.NAME.value] != '' or parse_cmd[Cmd.MESSAGE.value] != '':
            return False
    if parse_cmd[Cmd.COMMAND.value] == 'NAME':
        # if NAME don't have the name after command or have parameter
        if parse_cmd[Cmd.NAME.value] == '' or parse_cmd[Cmd.MESSAGE.value] != '':
            return False
    return True


def print_client_sockets(client_socket):
    for c in client_socket:
        print("\t", c.getpeername())


valid_msg = False
print("Setting up server...")
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind((SERVER_IP, SERVER_PORT))
server_socket.listen()
print("Listening for clients...")
client_sockets = []
messages_to_send = []
# try:
while True:
    rlist, w_list, xlist = select.select([server_socket] + client_sockets, client_sockets, [])
    for current_socket in rlist:
        if current_socket is server_socket:
            connection, client_address = current_socket.accept()
            print("New client joined!", client_address)
            client_sockets.append(connection)
            print_client_sockets(client_sockets)
        else:
            valid_msg, data = protocol.get_msg(current_socket)
            if valid_msg:
                if check_cmd(data) is False:
                    data = "Not allowed command, please try again"
                    messages_to_send.append((current_socket, data))
                elif data == "":
                    print("Connection closed", )
                    client_sockets.remove(current_socket)
                    current_socket.close()
                    print_client_sockets(client_sockets)
                else:
                    messages_to_send.append((current_socket, data))

    for message in messages_to_send:
        current_socket, data = message
        if current_socket in w_list:
            parsed_cmd = cmd_parser(data)
            server_response = create_server_rsp(data)
            if parsed_cmd[Cmd.COMMAND.value] == 'MSG':
                if parsed_cmd[Cmd.NAME.value] not in DIC.keys():
                    server_response = protocol.create_msg("Name doesnt exist")
                    current_socket.send(server_response.encode())
                else:
                    name = list(DIC.keys())[list(DIC.values()).index(current_socket)]
                    socket_for_send = DIC[parsed_cmd[Cmd.NAME.value]]
                    msg = protocol.create_msg(name + ' send ' + server_response)
                    socket_for_send.send(msg.encode())

            elif parsed_cmd[Cmd.COMMAND.value] == 'EXIT':

                print("Connection closed", )
                client_sockets.remove(current_socket)
                current_socket.close()
                print_client_sockets(client_sockets)
                name = list(DIC.keys())[list(DIC.values()).index(current_socket)]
                DIC.pop(name)
            else:
                current_socket.send(server_response.encode())
            messages_to_send.remove(message)

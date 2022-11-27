import socket
import select
import protocol

MAX_MSG_LENGTH = 1024
SERVER_PORT = 5555
SERVER_IP = '0.0.0.0'
DIC = {}


def cmd_parser(cmd):
    cmd_parsed = cmd.split(' ')
    cmd_name = cmd_parsed[0]
    if len(cmd_parsed) < 2:
        return [cmd_name, '', '']
    recipient_name = cmd_parsed[1]
    msg = ' '.join(cmd_parsed[2:])
    return [cmd_name[2:], recipient_name, msg]


def create_server_rsp(cmd):
    parsed_cmd = cmd_parser(cmd)
    if parsed_cmd[0] == 'NAME':
        if parsed_cmd[1] in DIC:
            return protocol.create_msg("This name is already exist please choose another name!\n")
        DIC.update({parsed_cmd[1]: current_socket})
        return protocol.create_msg("Hello " + parsed_cmd[1])
    if parsed_cmd[0] == 'GET_NAMES':
        return protocol.create_msg(' '.join(DIC.keys()))
    if cmd == "MSG":
        return protocol.create_msg(parsed_cmd[2])
    if cmd == "EXIT":
        return protocol.create_msg("EXIT")
    """Based on the command, create a proper response"""
    return protocol.create_msg("ERROR")


def check_cmd(data):
    parsed_cmd = cmd_parser(data)
    if parsed_cmd[0] in protocol.COMMANDS:
        return True
    """Check if the command is defined in the protocol """
    return False


def print_client_sockets(client_socket):
    for c in client_socket:
        print("\t", c.getpeername())


print("Setting up server...")
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind(("0.0.0.0", 5555))
server_socket.listen()
print("Listening for clients...")
client_sockets = []
messages_to_send = []
socket_dic = {}
while True:
    rlist, w_list, xlist = select.select([server_socket] + client_sockets, client_sockets, [])
    for current_socket in rlist:
        if current_socket is server_socket:
            connection, client_address = current_socket.accept()
            print("New client joined!", client_address)
            DIC.update({'a': client_address})
            client_sockets.append(connection)
            print_client_sockets(client_sockets)
        else:
            data = protocol.get_msg(current_socket)
            check_cmd(data)
            if data == "":
                print("Connection closed", )
                client_sockets.remove(current_socket)
                current_socket.close()
                print_client_sockets(client_sockets)
            else:
                messages_to_send.append((current_socket, data))
    for message in messages_to_send:
        current_socket, data = message
        if current_socket in w_list:
            #current_socket.send(data.encode())
            # current_socket.send(create_server_rsp('NAME AAA').encode())
            # current_socket.send(create_server_rsp('GET_NAMES').encode())
            parsed_cmd = cmd_parser(data)
            if parsed_cmd[0] == 'MSG':
                DIC[parsed_cmd[1]].send(create_server_rsp(data).encode())
            else:
                current_socket.send(create_server_rsp(data).encode())
            messages_to_send.remove(message)

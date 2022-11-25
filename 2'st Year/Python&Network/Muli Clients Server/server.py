import socket
import select
import protocol

MAX_MSG_LENGTH = 1024
SERVER_PORT = 5555
SERVER_IP = '0.0.0.0'


def create_server_rsp(cmd):
    if cmd == 'NAME':
        if
        return True
    if cmd == 'GET_NAMES':
        return protocol.create_msg('DHCP/DNS Server for your service')
    if cmd == "MSG":
        return protocol.create_msg()
    if cmd == "EXIT":
        return protocol.create_msg("EXIT")
    """Based on the command, create a proper response"""
    return protocol.create_msg("ERROR")


def check_cmd(data):
    if data in protocol.COMMANDS:
        return True
    """Check if the command is defined in the protocol (e.g NUMBER, HELLO, TIME, EXIT)"""
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
            client_sockets.append(connection)
            print_client_sockets(client_sockets)
        else:
            data = current_socket.recv(MAX_MSG_LENGTH).decode()
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
            current_socket.send(data.encode())
            messages_to_send.remove(message)

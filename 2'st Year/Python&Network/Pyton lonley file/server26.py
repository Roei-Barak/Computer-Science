"""EX 2.6 server implementation
   Author:Roei Barak
   Date:8/11/2022
   Possible client commands defined in protocol.py
"""
import datetime
import socket
import protocol
import random


def create_server_rsp(cmd):
    if cmd == 'NUMBER' or cmd == "RAND":
        return protocol.create_msg(random.randint(0, 99))
    if cmd == 'HELLO' or cmd == "WHORU" :
        return protocol.create_msg('DHCP/DNS Server for your service')
    if cmd == "TIME":
        return protocol.create_msg(datetime.datetime.now())
    if cmd == "EXIT":
        return protocol.create_msg("EXIT")
    """Based on the command, create a proper response"""
    return protocol.create_msg("ERROR")


def check_cmd(data):
    if data in protocol.COMMANDS :
        return True
    """Check if the command is defined in the protocol (e.g NUMBER, HELLO, TIME, EXIT)"""
    return False


def main():
    # Create TCP/IP socket object

    server_socket = socket.socket() #socket.AF_INET, socket.SOCK_STREAM
    # Bind server socket to IP and Port
    server_socket.bind(("0.0.0.0", 8820))
    # Listen to incoming connections
    server_socket.listen()
    print("Server is up and running")
    # Create client socket for incoming connection
    (client_socket, client_address) = server_socket.accept()
    print("Client connected")

    while True:

        # Get message from socket and check if it is according to protocol
        valid_msg, cmd = protocol.get_msg(client_socket)
        if valid_msg:
            # 1. Print received message
            print(f"{cmd}")
            # 2. Check if the command is valid, use "check_cmd" function
            if check_cmd(cmd):
            # 3. If valid command - create response
                response = create_server_rsp(cmd)
            else:
                response = "Wrong protocol"
                client_socket.recv(1024)  # Attempt to empty the socket from possible garbage

        else:
            response = "Wrong protocol"
            client_socket.recv(1024)  # Attempt to empty the socket from possible garbage


        # Send response to the client
        client_socket.send(response.encode())

        # If EXIT command, break from loop
        if (check_cmd(cmd)) and cmd == "EXIT":
            break
    print("Closing\n")
    # Close sockets
    client_socket.close()

if __name__ == "__main__":
    main()

"""
Server is up and running
Client connected
RAND
NUMBER
HELLO
WHORU
TIME
EXIT
Closing
"""
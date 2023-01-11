"""
Roei Barak
318419611
Client
"""

import socket
import msvcrt
import protocol
import select

MAX_MSG_LENGTH = 1024
SERVER_PORT = 5555
SERVER_IP = "127.0.0.1"
DIC = {}
CMD_LEN = 2

TIME_OUT: float = 0.1
my_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
my_socket.connect((SERVER_IP, SERVER_PORT))
user_input = input("Pls enter command\n")
client_sockets = []

while user_input != "EXIT":

    try:
        rlist, w_list, xlist = select.select([my_socket], client_sockets, [], TIME_OUT)

        if msvcrt.kbhit():
            while True:
                rlist, w_list, xlist = select.select([my_socket], client_sockets, [], TIME_OUT)
                if len(rlist) != 0:
                    valid_msg, ser_resp = protocol.get_msg(my_socket)
                    print('\n' + ser_resp + '\n' + user_input, end="")
                ch = msvcrt.getch()
                if ch == b"\r":
                    print('\n')
                    break
                if ch == b'\x08':
                    # Delete the last charters
                    user_input = user_input[:-1]
                else:
                    user_input = user_input + ch.decode()
                print(ch.decode(), end="", flush=True)

        if user_input != '':
            if user_input == 'EXIT':
                message = protocol.create_msg(user_input)
                my_socket.send(message.encode())
                my_socket.close()
                break
            # 1. Add length field ("HELLO" -> "04HELLO")
            message = protocol.create_msg(user_input)
            # 2. Send it to the server
            my_socket.send(message.encode())
            # 3. Get server's response
            if user_input[:2] == 'MSG':
                """End line for more readable """
                print('\n')

        for current_socket in rlist:
            valid_msg, server_resp = protocol.get_msg(my_socket)
            if server_resp == 'EXIT':
                my_socket.close()
                break
            if valid_msg:
                print("\nServer sent: ", server_resp)
            else:
                print("Wrong protocol")
        user_input = ''
    except:
        print("Server has been lost")
        break

my_socket.close()

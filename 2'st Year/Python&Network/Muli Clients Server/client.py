"""
Roei Barak
318419611
Client
"""

import socket
import msvcrt
import protocol
import select

TIME_OUT = 0.5
my_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
my_socket.connect(("127.0.0.1", 5555))
user_input = input("Pls enter msg\n")
client_sockets = []

while user_input != "EXIT":

    # if my_socket.close() == True:
    #     print("ASF")
    #     break
    try:
        rlist, w_list, xlist = select.select([my_socket], client_sockets, [],TIME_OUT)
        if msvcrt.kbhit():
            while True:
                rlist, w_list, xlist = select.select([my_socket], client_sockets, [],TIME_OUT )
                ch = msvcrt.getwche()
                if ch == '\r':
                    print('\n')
                    break
                user_input = user_input + ch
                # print(ch, end="", flush=True)
                # print(rlist)
                if len(rlist) != 0:
                    valid_msg, ser_resp = protocol.get_msg(my_socket)
                    print('\n' + ser_resp + '\n')
                    # server_resp = my_socket.recv(100)
                    # print(server_resp.decode())
                # for current_socket in rlist:
                #     print("0")
                #     valid_msg, server_resp = protocol.get_msg(my_socket)
                #     if server_resp == 'EXIT':
                #         my_socket.close()
                #         break
                #     if valid_msg:
                #         print("\nServer sent: ", server_resp)
                #     else:
                #         print("Wrong protocol")
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
    except :
        print("Server has been lost")
        break

my_socket.close()

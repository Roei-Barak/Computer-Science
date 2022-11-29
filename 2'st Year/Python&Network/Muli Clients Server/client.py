import socket
import msvcrt
import protocol
import select

my_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
my_socket.connect(("127.0.0.1", 5555))
user_input = input("Pls enter msg\n")
client_sockets = []
while user_input != "EXIT":

    rlist, w_list, xlist = select.select([my_socket], client_sockets, [], 0.5)
    if msvcrt.kbhit():
        print("1")
        while True:
            ch = msvcrt.getch().decode()
            # print(ch)
            if ch == '\r':
                print("Enter has been pressed")
                break
            user_input = user_input + ch
            print(ch, end="", flush=True)
    if user_input != '':

        # 1. Add length field ("HELLO" -> "04HELLO")
        message = protocol.create_msg(user_input)
        # 2. Send it to the server
        my_socket.send(message.encode())
        # 3. Get server's response
        # if user_input == "":
        #     print('4')
        #     continue
        # user_input = ""
        # print('3')
    for current_socket in rlist:
        print('4')

        valid_msg, server_resp = protocol.get_msg(my_socket)
        print('6')
        if valid_msg:
            print("Server sent: ",  server_resp)
        else:
            print("Wrong protocol")
    user_input = ''

my_socket.close()

import socket
import msvcrt
import protocol
import select

my_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
my_socket.connect(("127.0.0.1", 5555))
msg = input("Pls enter msg\n")
client_sockets = []

while msg != "EXIT":
    rlist, w_list, xlist = select.select([my_socket], client_sockets, [], 0.5)
    print("here1")
    if msvcrt.kbhit():
        while True:
            ch = msvcrt.getch().decode()
            # print(ch)
            if ch == '\r':
                print("ASd")
                break
            msg = msg + ch
            print(ch, end= "", flush=True)
    print("spme")
    my_socket.send(protocol.create_msg(msg).encode())
    msg = ""
    for current_socket in rlist:
        print("here socket")
        data = current_socket.recv(1024).decode()
        print("Server: ", data)


my_socket.close()
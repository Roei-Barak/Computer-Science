import socket
import msvcrt

my_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
my_socket.connect(("127.0.0.1", 5555))
msg = input("Pls enter msg\n")

while msg != "EXIT":

    if msvcrt.kbhit():
        while True:
            ch = msvcrt.getch().decode()
            print(ch)
            if ch == '\r':
                print("ASd")
                break
            msg = msg + ch
            print(msg)
            print(ch, end="", flush=True)
    print("spme")
    my_socket.send(msg.encode())
    data = my_socket.recv(1024).decode()
    print("Server: ", data)

my_socket.close()
import socket
import msvcrt

SERVER_PORT = 5555
my_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
my_socket.connect(("127.0.0.1", SERVER_PORT))
msg = input("pls enter message\n")

while msg != "EXIT":

    my_socket.send(msg.encode())
    data = my_socket.recv(1024).decode()
    print("server replied:", data)
    msg = input("Pls enter message\n")

my_socket.close()
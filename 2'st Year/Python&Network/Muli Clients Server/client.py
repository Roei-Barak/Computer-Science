import socket
import protocol
import msvcrt
while True:
    if not msvcrt.kbhit() :
        key_stroke = msvcrt.getch()
        if key_stroke==b'\x1b':
            print ("Esc key pressed")
        else:
            print (str(key_stroke).split("'")[1],"key pressed")
flush = False
ch3 = ''
while not msvcrt.kbhit() and ch3 != '\r':
    ch3 = msvcrt.getwche()

SERVER_PORT = 5555
my_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
my_socket.connect(("127.0.0.1", SERVER_PORT))
msg = msvcrt.getwch()

while msg != "EXIT":
    my_socket.send(msg.encode())
    data = my_socket.recv(1024).decode()
    print("server replied:", data)
    msg = input("Pls enter message\n")

my_socket.close()

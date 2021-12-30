#   Ex. 2.7 template - client side
#   Author:Roei Barak,318419611



import socket
import protocol

NOT_SEND_PHOTO = ["DIR", "DELETE", "EXECUTE", "COPY", "TAKE_SCREENSHOT"]
IP = "0.0.0.0"
SAVED_PHOTO_LOCATION = 'C:\\Networks\\work\\photo\\screen_shot_save‪.jpg'


def handle_server_response(my_socket, cmd):
    """
    Receive the response from the server and handle it, according to the request
    For example, DIR should result in printing the contents to the screen,
    Note- special attention should be given to SEND_PHOTO as it requires and extra receive
    """
    parse = cmd.split()
    command = parse[0]
    valid_res, server_response = protocol.get_msg(my_socket)
    if valid_res:
        # (8) treat all responses except SEND_PHOTO
        if command in NOT_SEND_PHOTO:
            print(server_response)
        # (10) treat SEND_PHOTO
        elif command == "SEND_PHOTO":
            print(server_response)
    else:
        print(server_response)


def main():
    # open socket with the server
    my_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    my_socket.connect(("127.0.0.1", protocol.PORT))
    # print instructions
    print('Welcome to remote computer application. Available commands are:\n')
    print('TAKE_SCREENSHOT\nSEND_PHOTO\nDIR\nDELETE\nCOPY\nEXECUTE\nEXIT')

    # loop until user requested to exit
    while True:
        cmd = input("Please enter command:\n")
        if protocol.check_cmd(cmd):
            packet = protocol.create_msg(cmd)
            my_socket.send(packet.encode())
            handle_server_response(my_socket, cmd)
            if cmd == 'EXIT':
                break
        else:
            print("Not a valid command, or missing parameters\n")

    my_socket.close()


if __name__ == '__main__':
    main()

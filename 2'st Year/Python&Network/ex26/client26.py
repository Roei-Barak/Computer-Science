"""EX 2.6 client implementation
   Author:Roei Barak
   Date:
"""

import socket
import protocol


def main():
    my_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    my_socket.connect(("127.0.0.1", protocol.PORT))

    while True:
        user_input = input("Enter command\n")
        valid_cmd = protocol.check_cmd(user_input)
        if valid_cmd:
            message = protocol.create_msg(user_input)
            my_socket.send(message.encode())
            if user_input == "EXIT":
                break
            valid_msg, cmd = protocol.get_msg(my_socket)
            if valid_msg:
                print(cmd)
            else:
                print("Response not valid\n")
        else:
            print("Not a valid command")

    print("Closing\n")
    # Close socket
    my_socket.close()


if __name__ == "__main__":
    main()

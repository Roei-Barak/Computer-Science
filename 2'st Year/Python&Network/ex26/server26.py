"""EX 2.6 server implementation
   Author:Roei Barak
   Date:
"""

import socket
import protocol


def main():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind(("0.0.0.0", protocol.PORT))
    server_socket.listen()
    print("Server is up and running")
    (client_socket, client_address) = server_socket.accept()
    print("Client connected")

    while True:
        # Get message from socket and check if it is according to protocol
        valid_msg, cmd = protocol.get_msg(client_socket)
        if valid_msg:
            print(cmd)
            # 2. Check if the command is valid
            if protocol.check_cmd(cmd):
                # 3. If valid command - create response
                pre_response = protocol.create_server_rsp(cmd)
                response = protocol.create_msg(pre_response)
            else:
                response = "Wrong command"
                response = protocol.create_msg(response)
        else:
            response = "Wrong protocol"
            response = protocol.create_msg(response)
            client_socket.recv(1024)  # Attempt to empty the socket from possible garbage
        # Handle EXIT command, no need to respond to the client
        if cmd != "EXIT":
            client_socket.send(response.encode())
        else:
            break
        # Send response to the client
        # message = protocol.create_msg(response)
        # server_socket.send(message.encode())
    print("Closing\n")
    # Close sockets
    client_socket.close()
    server_socket.close()


if __name__ == "__main__":
    main()

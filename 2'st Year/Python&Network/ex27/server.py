#   Ex. 2.7 template - server side
#   Author:Roei Barak,318419611
#   Modified for Python 3, 2020

import socket
import protocol
import os
import glob
import shutil
import subprocess
import pyautogui

# Brodcast IP 0.0.0.0
IP = "0.0.0.0"

PHOTO_PATH = 'C:\\Networks\\work\\photo\\screen_shot‪.jpg'

# The path + filename where the screenshot at the server should be saved


def check_client_request(cmd):
    """
    Break cmd to command and parameters
    Check if the command and params are good.

    For example, the filename to be copied actually exists

    Returns:
        valid: True/False
        command: The requested cmd (ex. "DIR")
        params: List of the cmd params (ex. ["c:\\cyber"])
    """
    # Use protocol.check_cmd first
    if protocol.check_cmd(cmd):
        cmd_arg = cmd.split()
        command = cmd_arg[0]
        if (command == "DIR") or (command == "EXECUTE"):
            arg = cmd_arg[1]
            if os.path.exists(arg):
                return True, command, arg
            else:
                return False, "ERROR", "ERROR"
        if command == "DELETE":
            arg = cmd_arg[1]
            if os.path.isfile(arg):
                return True, command, arg
            else:
                return False, "ERROR", "ERROR"
        if command == "COPY":
            arg = cmd_arg[1]
            if os.path.isfile(arg):
                arg_2 = cmd_arg[2]
                return True, command, arg, arg_2
            else:
                return False, "ERROR", "ERROR"
        if (command == "EXIT") or (command == "TAKE_SCREENSHOT") or (command == "SEND_PHOTO"):
            return True, command, "no params"
    return False, "ERROR", "ERROR"



def handle_client_request(command, params):
    """Create the response to the client, given the command is legal and params are OK

    For example, return the list of filenames in a directory
    Note: in case of SEND_PHOTO, only the length of the file will be sent

    Returns:
        response: the requested data

    """
    pth = params[0]
    new_pth = params[1]
    response = 'OK'
    if command == "DIR":
        files_list = glob.glob(r''+ pth)
        response = files_list
    if command == "DELETE":
        file_to_remove = str(pth)
        os.remove(file_to_remove)
        response = "successfully File Deleted"
    if  command == "COPY":
        if pth == new_pth:
            return "Same dirctory"
        shutil.copy(str(pth),str(new_pth))
        response ="successfully Copy File"
    if command == "EXECUTE":
        subprocess.call(str(pth))
        response ="successfully Execute Program"
    if  command == "TAKE_SCREENSHOT":
        img = pyautogui.screenshot()
        img.save(PHOTO_PATH)
        response = "successfully Take a Screenshot"
    return response


def main():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind(("0.0.0.0", protocol.PORT))
    server_socket.listen()
    print("Server is up and running")
    (client_socket, client_address) = server_socket.accept()
    print("Client connected")
    # handle requests until user asks to exit
    while True:
        # Check if protocol is OK, e.g. length field OK
        valid_protocol, cmd = protocol.get_msg(client_socket)
        if valid_protocol:
            # Check if params are good, e.g. correct number of params, file name exists
            valid_cmd, command, params = check_client_request(cmd)
            if valid_cmd:
                # prepare a response using "handle_client_request"
                response = handle_client_request(command,params)
                # add length field using "create_msg"
                create_rsp = protocol.create_msg(response)
                # send to client
                client_socket.send(create_rsp.encode())
                if command == 'SEND_FILE':
                    # Send the data itself to the client
                    picture_open_binary = open(PHOTO_PATH, 'rb')
                    client_socket.send(picture_open_binary.read(int(response)))
                if command == 'EXIT':
                    break
            else:
                # prepare proper error to client
                response = 'Bad command or parameters'
                # send to client
                client_socket.send(response.encode())

        else:
            # prepare proper error to client
            response = 'Packet not according to protocol'
            #send to client
            create_resp = protocol.create_msg(response)
            client_socket.send(create_resp.encode())
            # Attempt to clean garbage from socket
            client_socket.recv(1024)

    # close sockets
    client_socket.close()
    server_socket.close()
    print("Closing connection")


if __name__ == '__main__':
    main()

# Ex 4.4 - HTTP Server Shell
# Author: Barak Gonen
# Purpose: Provide a basis for Ex. 4.4
# Note: The code is written in a simple way, without classes, log files or other utilities, for educational purpose
# Usage: Fill the missing functions and constants

# TO DO: import modules

import socket
import os
from scapy.all import *

def filter_dns(packet):
    if DNSQR in packet:
        return 91


# TO DO: set constants
ROOT_DIR = r'C:\Networks\webroot'
DEFAULT_URL = "index.html"
CODE = "200 OK"
IP = '0.0.0.0'
PORT = 80
SOCKET_TIMEOUT = 0.1 


def get_file_data(filename):
    """ Get data from file """
    #file = open(ROOT_DIR + '\\' + filename, 'rb')
    filename = filename.replace('/', '\\')
    name = ROOT_DIR + '\\' + filename
    if os.path.isfile(name) is True:
        file = open(name, 'rb')
        data = file.read()
        return data


def handle_client_request(resource, client_socket):
    """ Check the required resource, generate proper HTTP response and send to client"""
    # TO DO : add code that given a resource (URL and parameters) generates the proper response
    if resource == '/':
        url = DEFAULT_URL
    else:
        url = resource[1:]

    # TO DO: check if URL had been redirected, not available or other error code. For example:
    # if url in REDIRECTION_DICTIONARY:
    # TO DO: send 302 redirection response
    point = url.find('.', -5, -1)
    file_type = url[point + 1:]
    http_header = "HTTP /1.1 200 OK\r\n"
    # TO DO: extract requested file tupe from URL (html, jpg etc)
    if file_type == 'html':
        http_header += "Content-Type: text/html; charset = utf-8"
    elif file_type == 'jpg' or file_type == 'ico':
        http_header += "Content-Type: image/jpeg"
    elif file_type == 'js':
        http_header += "Content-Type: text/javascript; charset=UTF-8"
    elif file_type == 'css':
        http_header += "Content-Type: text/css"
        # TO DO: generate proper jpg header

    # TO DO: read the data from the file
    filename = url
    data = get_file_data(filename)
    http_response = http_header + ("Content-Length: " + str(len(data)) + "\r\n\r\n")
    client_socket.send(http_response.encode() + data)


def validate_http_request(request):
    """
    Check if request is a valid HTTP request and returns TRUE / FALSE and the requested URL
    """
    # first part of the http request
    if not request[0:3] == 'GET' or not request[3] == ' ':
        return False

    # url part
    second_space = request.find(' ', 5, -1)
    if not request[second_space:second_space + 9] == ' HTTP/1.1':
        return False
    return True, request[4:second_space]


def handle_client(client_socket):
    """ Handles client requests: verifies client's requests are legal HTTP, calls function to handle the requests """
    print('Client connected')
    # client_socket.send(FIXED_RESPONSE.encode())
    while True:
        # TO DO: insert code that receives client request
        # ...
        client_request = client_socket.recv(1024).decode()
        valid_http, resource = validate_http_request(client_request)
        if valid_http:
            print('Got a valid HTTP request')
            handle_client_request(resource, client_socket)
            break
        else:
            print('Error: Not a valid HTTP request')
            break
    print('Closing connection')
    client_socket.close()


def main():
    # Open a socket and loop forever while waiting for clients
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind((IP, PORT))
    server_socket.listen()
    print("Listening for connections on port {}".format(PORT))

    while True:
        client_socket, client_address = server_socket.accept()
        print('New connection received')
        client_socket.settimeout(SOCKET_TIMEOUT)
        handle_client(client_socket)


if __name__ == "__main__":
    # Call the main handler function
    main()

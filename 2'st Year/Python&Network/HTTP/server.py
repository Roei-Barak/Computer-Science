# Ex 4.4 - HTTP Server Shell
# Author: Barak Gonen
# Purpose: Provide a basis for Ex. 4.4
# Note: The code is written in a simple way, without classes, log files or other utilities, for educational purpose
# Usage: Fill the missing functions and constants

# TO DO: import modules
import os
import socket

# import validators
#
# valid=validators.url('https://www.codespeedy.com/')
# TO DO: set constants
IP = '0.0.0.0'
PORT = 80
SOCKET_TIMEOUT = 0.1
HTTP_VER = 'HTTP/1.1'
REDIRECTION_DICTIONARY = []

DEFAULT_URL = "C:/Networks/webroot/index.html"
ROOT_DIR = r'C:\Networks\webroot'
FIXED_RESPONSE = "HTTP /1.1 200 OK\r\nContent-Length: 9\r\nContent-Type: text/html\r\n\r\n 008880808008"


def get_file_data(filename):
    """ Get data from file """
    if filename == '404.html':
        file = open( ROOT_DIR + '\\' + 'css' + '\\' + filename, 'rb')
        data = file.read()
        return data
    split_filename = filename.split('.')
    filetype = split_filename[-1]
    directory = ''
    if filetype == 'html' or filetype == 'text':
        directory = ''
    elif filetype == 'jpg' or filetype == 'ico':
        directory = 'imgs'
    elif filetype == 'js':
        directory = 'js'
    elif filetype == 'css':
        directory = 'css'
    filename = filename.replace('/', '\\')
    name = ROOT_DIR + '\\' + directory + '\\' + filename
    if os.path.isfile(name) is True:
        file = open(name, 'rb')
        data = file.read()
        return data
    return False


def validate_url(url):
    url_split = url.split('.')
    if url_split[0] != 'www':
        return False
    if url_split[1] == '':
        return False
    if url_split[2] == 'com' or (url_split[2] == 'co' and url_split[3] == 'il'):
        return True
    return False


def handle_client_request(resource, client_socket):
    """ Check the required resource, generate proper HTTP response and send to client"""
    # TO DO : add code that given a resource (URL and parameters) generates the proper response

    if resource == '/':
        url = DEFAULT_URL
        filetype = 'html'
    else:
        url = resource
        dot_index = url.rfind('.')
        filetype = url[dot_index + 1:]
    url_parse = url.split('/')
    # # TO DO: check if URL had been redirected, not available or other error code.
    if url in REDIRECTION_DICTIONARY:
        url = DEFAULT_URL
        filetype = 'html'
        http_header = "HTTP /1.1 302 Found\r\n"
        # TO DO: send 302 redirection response
    elif get_file_data(url_parse[-1]) is False:
        http_header = "HTTP /1.1 404 Not Found\r\n"
        url = ROOT_DIR
        url_parse[-1] = '404.html'
        filetype = 'html'
    else:
        http_header = "HTTP /1.1 200 OK\r\n"

    # TO DO: extract requested file tupe from URL (html, jpg etc)
    if filetype == 'html' or filetype == 'text':
        http_header += "Content-Type: text/html; charset = utf-8 "
    elif filetype == 'jpg' or filetype == 'ico':
        http_header += 'Content-Type: image/jpeg'
    elif filetype == 'js':
        http_header += 'Content-Type: text/javascript; charset=UTF-8 '
    elif filetype == 'css':
        http_header += 'Content-Type: text/css; charset=UTF-8 '

    # TO DO: read the data from the file
    data = get_file_data(url_parse[-1])
    http_response = http_header + ("Content-Length: " + str(len(data)) + "\r\n\r\n")
    client_socket.send(http_response.encode() + data)


def validate_http_request(request):
    """
    Check if request is a valid HTTP request and returns TRUE / FALSE and the requested URL
    """
    split_request = request.split(' ')
    if split_request[0] != 'GET':
        return False, []
    if split_request[1] == '':
        return False
    if (split_request[2])[:10] != HTTP_VER + '\r\n':
        return False
    # TO DO: write function
    return True, split_request[1]


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

# Ex 4.4 - HTTP Server Shell
# Author: Barak Gonen
# Purpose: Provide a basis for Ex. 4.4
# Note: The code is written in a simple way, without classes, log files or other utilities, for educational purpose
# Usage: Fill the missing functions and constants

# TO DO: import modules

import socket
import os
from scapy.all import *
from scapy.layers.dns import DNS, DNSQR
from scapy.layers.inet import UDP, IP

# TO DO: set constants
ROOT_DIR = r'C:\Networks\webroot'
DEFAULT_URL = "index.html"
CODE = "200 OK"
BIND_IP = '0.0.0.0'
PORT = 8153
SOCKET_TIMEOUT = 20
REVERSE = "/reverse/"


def revers_nslookup(ip):
    dns_request = IP(dst='8.8.8.8') / UDP(sport=24601, dport=53) / DNS(qdcount=1, rd=1) / DNSQR(qname=ip)
    dns_response = sr1(dns_request)
    data = dns_response[DNS].ns.rname
    return data

def nslookup(name):
    dns_request = IP(dst='8.8.8.8') / UDP(sport=24601, dport=53) / DNS(qdcount=1, rd=1) / DNSQR(qname=name)
    dns_response = sr1(dns_request)

    if dns_response.rcode == 0:
        for answer in dns_response[DNS]:
            data = answer.an.rdata + '\n'
    else:
        return "Error"
    return data

    # ip_addresses =[rr.rdata for rr in dns_response.an]
    # return ip_addresses


def handle_client_request(resource, client_socket):
    data = ''
    """ Check the required resource, generate proper HTTP response and send to client"""
    if resource[:9] == REVERSE:
        url = resource[9:]
        data = revers_nslookup(url).decode()
    else:
        url = resource[1:]
        ip_list = nslookup(url)
        data = " ".join(ip_list)
        if ip_list == "Error":
            data = "Error"

    http_header = "HTTP /1.1 200 OK\r\n\r\n"

    http_response = http_header + data

    client_socket.send(http_response.encode())


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
    server_socket.bind((BIND_IP, PORT))
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

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
TIMEOUT = 10
DEFAULT_URL = "index.html"
BIND_IP = '0.0.0.0'
PORT = 8153
SOCKET_TIMEOUT = 20
DESTINATION_PORT = 53
SOURCE_PORT = 24601
MAX_LENGTH_SIZE = 1024
GOOGLE = '8.8.8.8'
REVERSE = "/reverse/"


def check_ip(ip):
    ip_seperat = ip.split('.')
    if not len(ip_seperat) == 4:
        return False
    for num in ip_seperat:
        if num.isnumeric():
            if 0 < int(num) < 256:
                continue
            else:
                return False
        else:
            return False
    return True


def revers_nslookup(ip):
    if check_ip(ip) is False:
        return "Not a valid ip".encode()
    dns_request = IP(dst=GOOGLE) / UDP(sport=SOURCE_PORT, dport=DESTINATION_PORT) / DNS(qdcount=1, rd=1) / DNSQR(
        qname=ip + ".in-addr.arpa", qtype="PTR")
    dns_response = sr1(dns_request, timeout=TIMEOUT, verbose=False)
    if dns_response[DNS].ancount > 0:
        ptr_record = dns_response[DNS].an[0]
        hostname = ptr_record.rdata
        return hostname
    else:
        return ("No hostname found for IP address: " + str(ip)).encode()


def nslookup(name):
    if name[:4] != 'www.':
        name = 'www.' + name
    dns_request = IP(dst=GOOGLE) / UDP(sport=SOURCE_PORT, dport=DESTINATION_PORT) / \
                  DNS(qdcount=1, rd=1) / DNSQR(qname=name)

    dns_response = sr1(dns_request, timeout=TIMEOUT, verbose=False)
    if dns_response == None:
        return 'None'
    data = ''
    number_of_ans = dns_response[DNS].ancount
    if not number_of_ans == 0:
        for i in range(number_of_ans):
            if dns_response.an[i].type == 1:  # type A not a CNAME
                data += dns_response.an[i].rdata + '\n'
    else:
        return "ERROR"
    print(data)
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
    client_socket.settimeout(10)
    try:
        while True:
            client_request = client_socket.recv(MAX_LENGTH_SIZE).decode()
            valid_http, resource = validate_http_request(client_request)
            if valid_http:
                print('Got a valid HTTP request')
                handle_client_request(resource, client_socket)
                break
            else:
                print('Error: Not a valid HTTP request')
                break
    except socket.timeout:
        print('Closing connection')
    print('Closing connection')

    client_socket.close()


def main():
    # Open a socket and loop forever while waiting for clients
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind((BIND_IP, PORT))
    server_socket.listen()
    print("Listening for connections on port {}".format(PORT))

    while True:
        try:
            client_socket, client_address = server_socket.accept()
            print('New connection received')
            client_socket.settimeout(SOCKET_TIMEOUT)
            handle_client(client_socket)
        except:
            print("ERROR")


if __name__ == "__main__":
    # Call the main handler function
    main()

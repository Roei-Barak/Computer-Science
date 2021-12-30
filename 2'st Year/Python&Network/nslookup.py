import sys

i, o, e = sys.stdin, sys.stdout, sys.stderr
from scapy.all import *

sys.stdin, sys.stdout, sys.stderr = i, o, e

ROOT_SERVER = '198.41.0.4'

# def revers(ip):
#     dns_packet = IP(dst='8.8.8.8') / UDP(sport=24601, dport=53) / DNS(qdcount=1, rd=1) / DNSQR(qname='www.google.com')
#     response_packet = sr1()
#
#
# def print_DNS_qname(dns_packet):
#     print(dns_packet[DNSQR].qname)
#
#
# def filter_DNS_A(packet):
#     if (DNS in packet) and (DNSQR in packet):
#         return (packet[DNS].opcode == 0) and (packet[DNSQR].qtype == 1)
#
#
# print("Starting to sniff!")
# p = sniff(count=10, lfilter=filter_DNS_A, prn=print_DNS_qname)

def recurse(domain_name):
    dns_packet = IP(dst='8.8.8.8') / UDP(sport=24601, dport=53) / DNS(qdcount=1, rd=1) / DNSQR(qname='{}.in-addr.arpa'.format(domain_name))
    dns_packet.show()
    response_packet = sr1(dns_packet)
    response_packet.show()
    recurse(response_packet.ns[0].rname.decode())

def main():

    dns_packet = IP(dst='8.8.8.8') / UDP(sport=24601, dport=53) / DNS(qdcount=1, rd=1) / DNSQR(qname='www.Facebook.com')
    dns_packet.show()
    response_packet = sr1(dns_packet)
    response_packet.show()

    recurse('www.Facebook.com')

if __name__ == '__main__':
    main()

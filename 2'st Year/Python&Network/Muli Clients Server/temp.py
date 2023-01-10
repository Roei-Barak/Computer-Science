# import os
# from scapy.all import *
# from scapy.layers.dns import DNS, DNSQR
# from scapy.layers.inet import UDP
#
# def filter_dns(packet):
#     if DNSQR in packet:
#         return (packet[DNS].opcode == 0) and (packet[DNSQR].qtype == 1)
#
# def print_query_name(dns_packet):
#     print(dns_packet[DNSQR].qname.decode())
#
# sniff(count =10, lfilter=filter_dns, prn=print_query_name())
import msvcrt

a = msvcrt.getch()
print(a)
while a != b'\r':
    print(a.decode(), end="",flush=True)
    a = msvcrt.getch()
    if a == b'\x08':
        a = a[:-1]
        print('08')
print(a)
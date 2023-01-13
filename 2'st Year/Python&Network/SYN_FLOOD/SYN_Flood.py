from scapy.all import *
from scapy.layers.inet import IP, TCP

IP_list = []


def check(pkt):
    if pkt.haslayer(TCP):
        if pkt[IP][TCP].flags == 'S' and pkt[IP].src[]:
            return True


pcapFile = rdpcap("SYNflood.pcapng")

# tcp.flags.syn ==1 and tcp.flags.ack ==0

for pkt in pcapFile:

    if check(pkt):
        with open("temp.txt", "w") as f:
            f.write(pkt[IP].src)
        print(pkt.time)
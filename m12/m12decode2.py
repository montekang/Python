import socket
import os
import struct
import threading
from ctypes import *

# host to listen on
host = "10.187.136.253"

class IP(Structure):
    
    _fields_ = [
        ("ihl",           c_byte, 4),
        ("version",       c_byte, 4),
        ("tos",           c_byte),
        ("len",           c_short),
        ("id",            c_short),
        ("offset",        c_short),
        ("ttl",           c_byte),
        ("protocol_num",  c_byte),
        ("sum",           c_short),
        ("src",           c_uint32),
        ("dst",           c_uint32)
    ]
    
    def __new__(self, socket_buffer=None):
            return self.from_buffer_copy(socket_buffer)    
        
    def __init__(self, socket_buffer=None):

        # map protocol constants to their names
        self.protocol_map = {1:"ICMP", 6:"TCP", 17:"UDP"}
        
        # human readable IP addresses
        self.src_address = socket.inet_ntoa(struct.pack("@I",self.src))
        self.dst_address = socket.inet_ntoa(struct.pack("@I",self.dst))
    
        # human readable protocol
        try:
            self.protocol = self.protocol_map[self.protocol_num]
        except:
            self.protocol = str(self.protocol_num)
            


class ICMP(Structure):
    
    _fields_ = [
        ("type",         c_ubyte),
        ("code",         c_ubyte),
        ("checksum",     c_ushort),
        ("unused",       c_ushort),
        ("next_hop_mtu", c_ushort)
        ]
    
    def __new__(self, socket_buffer):
        return self.from_buffer_copy(socket_buffer)    

    def __init__(self, socket_buffer):
        pass

# create a raw socket and bind it to the public interface
if os.name == "nt":
    socket_protocol = socket.IPPROTO_IP 
else:
    socket_protocol = socket.IPPROTO_ICMP
    
sniffer = socket.socket(socket.AF_INET, socket.SOCK_RAW, socket_protocol)

sniffer.bind((host, 0))

# we want the IP headers included in the capture
sniffer.setsockopt(socket.IPPROTO_IP, socket.IP_HDRINCL, 1)

# if we're on Windows we need to send some ioctls
# to setup promiscuous mode
if os.name == "nt":
    sniffer.ioctl(socket.SIO_RCVALL, socket.RCVALL_ON)

print "My IP: %s" % host

try:
    while True:

        
        # read in a single packet
        raw_buffer = sniffer.recvfrom(65535)[0]
        
        # create an IP header from the first 20 bytes of the buffer
        ip_header = IP(raw_buffer[0:20])
	    #print "My IP: %s " % host
        #print "Proto: %s %s -> %s" % (ip_header.protocol, ip_header.src_address, ip_header.dst_address)
    
        # if it's ICMP we want it
        if ip_header.protocol == "ICMP":
            
            # calculate where our ICMP packet starts
            offset = ip_header.ihl * 4
            buf = raw_buffer[offset:offset + sizeof(ICMP)]
            
            # create our ICMP structure
            icmp_header = ICMP(buf)
	    #print "Host up: %s " % host
            print "Proto: %s %s -> %s" % (ip_header.protocol, ip_header.src_address, ip_header.dst_address),   "ICMP -> Type: %d Code: %d" % (icmp_header.type, icmp_header.code)
	    print "Host up: %s" % host

            #print "ICMP -> Type: %d Code: %d" % (icmp_header.type, icmp_header.code)
            
# handle CTRL-C
except KeyboardInterrupt:
    # if we're on Windows turn off promiscuous mode
    if os.name == "nt":
        sniffer.ioctl(socket.SIO_RCVALL, socket.RCVALL_OFF)


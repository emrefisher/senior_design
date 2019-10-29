#!/usr/bin/python3

import socket

HOST = '192.168.10.177'  # IP address or hostname of server
PORT = 49173            # an open port (1000+ recommended), must match the server port
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)    # UDP
#s.connect((HOST,PORT))



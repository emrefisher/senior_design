#!/usr/bin/python3

import socket

# IP address or hostname of server
HOST = '192.168.10.177'  # arduino ethernet shield
#HOST = '192.168.10.30'      # 6k4
#HOST = '192.168.10.34'  # computer
PORT = 12345            # an open port (1000+ recommended), must match the server port
# PORT 1234 -- arduino

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)   # TCP/IP
s.connect((HOST,PORT))

# wait for input
while True:
    command = input("message: ").encode()
    s.send(command)
    #s.sendall('helloworld'.encode())

    reply = (s.recv(1024)).decode()
    #reply = (s.recv(1024))
    #if HOST == '192.168.10.34':
    #    if command == 'quit':
    #        break
    print(reply)

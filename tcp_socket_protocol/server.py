#!/usr/bin/python3

import socket

HOST = '192.168.10.34'  # IP address or hostname of server
PORT = 12345            # an open port (1000+ recommended), must match the client port

try:
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    print('socket created...')
    s.bind((HOST,PORT))
except socket.error:
    print('socket bind failed...')

s.listen(5)
print('waiting for message...')
(conn, addr) = s.accept()
print('connected...')

while True:
    data = conn.recv(1024).decode()
    print('data: ' + data)
    response = ('received').encode()
    conn.send(response)

    if data == 'quit':
        #conn.send('quit'.encode())
        conn.close()
        break


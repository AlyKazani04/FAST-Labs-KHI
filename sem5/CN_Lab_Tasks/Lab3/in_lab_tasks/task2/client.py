import socket as s

sock = s.socket()

PORT = 3000
sock.connect(("localhost", PORT))

sock.send(input("Enter your name: ").encode())

print(sock.recv(512).decode())

sock.close()

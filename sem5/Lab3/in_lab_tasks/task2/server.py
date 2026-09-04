import socket as s

sock = s.socket()

PORT = 3000
sock.bind(("localhost", PORT))

sock.listen(1)

conn, addr = sock.accept()

name = conn.recv(512).decode()
conn.send(f"Welcome, {name}, to the university server!".encode())

conn.close()
sock.close()

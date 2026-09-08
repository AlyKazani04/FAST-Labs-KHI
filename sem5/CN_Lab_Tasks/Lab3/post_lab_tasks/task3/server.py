import socket as s

sock = s.socket()

PORT = 3001
sock.bind(("localhost", PORT))

sock.listen(1)
print(f"Server is up and running at port {PORT}")

conn, addr = sock.accept()
print(f"Client connected at {addr[0]}:{addr[1]}!")

msg = conn.recv(512).decode()
print(f"Message from client: {msg}")

conn.close()
sock.close()

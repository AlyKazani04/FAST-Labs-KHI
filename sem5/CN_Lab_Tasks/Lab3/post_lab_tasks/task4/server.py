import json
import socket as s

sock = s.socket()

PORT = 3001
sock.bind(("localhost", PORT))

sock.listen(1)
print(f"Server is listening at port {PORT}...")

conn, addr = sock.accept()
print(f"Client connected at {addr[0]}:{addr[1]}!")

data = conn.recv(1024).decode()
student = json.loads(data)
print(f"Student ID: {student['id']}")
print(f"Student Name: {student['name']}")
print(f"Department: {student['department']}")

conn.send("Recieved!".encode())

conn.close()
sock.close()

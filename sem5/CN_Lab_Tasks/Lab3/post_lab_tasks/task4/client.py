import json
import socket as s

sock = s.socket()

PORT = 3001
sock.connect(("localhost", PORT))

print("--Student Information--")
id = input("Student ID: ")
name = input("Student Name: ")
dept = input("Department: ")

data = json.dumps({"id": id, "name": name, "department": dept})
sock.send(data.encode())

print(f"Server: {sock.recv(512).decode()}")

sock.close()

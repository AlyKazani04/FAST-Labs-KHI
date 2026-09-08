import socket as s

sock = s.socket()

PORT = 3001
sock.connect(("localhost", PORT))
print("Connected to Department Message Channel!")

msg = input("Enter Message for department: ")
sock.send(msg.encode())

sock.close()

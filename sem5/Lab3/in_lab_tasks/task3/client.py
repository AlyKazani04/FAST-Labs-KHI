import socket as s

sock = s.socket()

PORT = 3000
sock.connect(("localhost", PORT))

while 1:
    text = input("Client: ")

    sock.send(text.encode())

    print(f"Server: {sock.recv(512).decode()}")

    if text == "bye":
        break

sock.close()

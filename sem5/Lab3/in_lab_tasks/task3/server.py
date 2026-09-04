import socket as s

sock = s.socket()

PORT = 3000
sock.bind(("localhost", PORT))

sock.listen(1)

conn, addr = sock.accept()

while 1:
    text = conn.recv(512).decode()

    print(text)

    conn.send(f"Received: {text}".encode())

    if text == "bye":
        break

conn.close()
sock.close()

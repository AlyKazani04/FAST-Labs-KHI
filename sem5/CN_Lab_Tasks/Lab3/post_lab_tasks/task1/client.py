import socket as s

sock = s.socket()

PORT = 3001
sock.connect(("localhost", PORT))

prompt = sock.recv(512).decode()
while True:
    try:
        number = int(input(prompt))
        break
    except ValueError:
        print("Value needed is any valid number. Try again.")

sock.send(str(number).encode())

prompt = sock.recv(512).decode()
while True:
    try:
        number = int(input(prompt))
        break
    except ValueError:
        print("Value needed is any valid number. Try again.")

sock.send(str(number).encode())

prompt = sock.recv(512).decode()
while True:
    try:
        number = int(input(prompt))
        if number in [1, 2, 3, 4, 0]:
            break
        else:
            raise ValueError
    except ValueError:
        print("Enter a valid value. (0, 1, 2, 3, 4)")

sock.send(str(number).encode())

result = sock.recv(512).decode()
print(f"\n{result}")

sock.close()

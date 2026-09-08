import socket as s


def add(n1, n2):
    return n1 + n2


def subtract(n1, n2):
    return n1 - n2


def multiply(n1, n2):
    return n1 * n2


def divide(n1, n2):
    if n2 == 0:
        return None
    return n1 / n2


sock = s.socket()

PORT = 3001
sock.bind(("localhost", PORT))

sock.listen(1)
print(f"Server is listening on port {PORT}...")

conn, addr = sock.accept()

conn.send("Enter a number: ".encode())
num1 = int(conn.recv(512).decode())

conn.send("Enter another number: ".encode())
num2 = int(conn.recv(512).decode())

selection_prompt = """
Select an operator:
Type 1 for addition
Type 2 for subtraction
Type 3 for multiplication
Type 4 for division
Type 0 to exit
> """
conn.send(selection_prompt.encode())
selection = int(conn.recv(512).decode())

response = ""
match selection:
    case 1:
        res = add(num1, num2)
        response = f"Result: {res}"
    case 2:
        res = subtract(num1, num2)
        response = f"Result: {res}"
    case 3:
        res = multiply(num1, num2)
        response = f"Result: {res}"
    case 4:
        res = divide(num1, num2)
        if res is None:
            response = "Error Division by zero is not allowed"
        else:
            response = f"Result: {res}"
    case 0:
        response = "Exiting..."
    case _:
        response = "Unknown Case Reached! Exiting..."

conn.send(response.encode())

print("Connection Closed.")
conn.close()
sock.close()

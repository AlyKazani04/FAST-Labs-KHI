import socket as s
import json

MAX_COURSES = 2

sock = s.socket()

PORT = 4321
sock.bind(("localhost", PORT))

sock.listen(1)
print(f"Server up and listening on {PORT}...")

conn, addr = sock.accept()
print(f"Client connected at {addr[0]}:{addr[1]}!")

try:
    data = conn.recv(1024).decode()
    if data:
        new_data = json.loads(data)
        try:
            with open("db.json", "r") as file:
                db = json.load(file)
        except (FileNotFoundError, json.JSONDecodeError):
            db = {"students": []}
        db["students"].extend(new_data)

        with open("db.json", "w") as file:
            json.dump(db, file, indent=2)

        response = json.dumps(db).encode()
        conn.send(response)
except Exception as e:
    print(f"--Error--\n{e}")

conn.close()
sock.close()

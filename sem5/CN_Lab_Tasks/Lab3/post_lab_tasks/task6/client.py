import json
import socket as s

MAX_COURSES = 2

sock = s.socket()

PORT = 3001
sock.connect(("localhost", PORT))

courses = []
for i in range(MAX_COURSES):
    course = {}
    print(f"Course {i + 1}")
    course["name"] = input("Enter Course Name: ")
    course["hours"] = int(input("Enter Course Hours: "))
    course["grade"] = input("Enter Letter Grade: ")
    courses.append(course)

msg = json.dumps(courses)

sock.send(msg.encode())

report = sock.recv(1024).decode()
print(f"--Report--\n{report}")

sock.close()

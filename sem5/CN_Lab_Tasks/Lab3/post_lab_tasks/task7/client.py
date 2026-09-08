import json
import socket as s

sock = s.socket()

PORT = 3001
sock.connect(("localhost", PORT))

student = {}
print("Enter Student Information")
student["student_id"] = input("Enter Student ID: ")
student["name"] = input("Enter Name: ")
student["department"] = input("Enter Department: ")
student["semester"] = int(input("Enter Semester: "))
student["gpa"] = float(input("Enter GPA: "))

msg = json.dumps(student)

sock.send(msg.encode())

display = sock.recv(1024).decode()
print(f"\n--Student Information--\n{display}")

sock.close()

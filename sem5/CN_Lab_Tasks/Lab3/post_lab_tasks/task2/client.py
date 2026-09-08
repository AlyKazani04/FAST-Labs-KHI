import socket as s
import json

MAX_COURSES = 2


class Student:
    def __init__(self, name):
        self.name = name
        self.marks = {}
        self.total = 0
        self.percentage = 0

    def get_marks(self):
        print("--Marks Registration--")
        for i in range(MAX_COURSES):
            sub = input("Subject Name: ")
            mark = int(input("Subject Marks: "))
            self.marks[sub] = mark
        print(self.marks)

    def calculate_total(self):
        self.total = sum(self.marks.values())

    def calculate_percentage(self):
        self.percentage = self.total / (MAX_COURSES * 100)

    def json_format(self):
        return {
            "name": self.name,
            "marks": self.marks,
            "total": self.total,
            "percentage": self.percentage,
        }


student_list = []
num_students = int(input("Enter number of students to log: "))
for i in range(num_students):
    name = input("Enter name of student: ")
    student = Student(name)
    student.get_marks()
    student.calculate_total()
    student.calculate_percentage()
    student_list.append(student)

sock = s.socket()

PORT = 4321
sock.connect(("localhost", PORT))

data = json.dumps([student.json_format() for student in student_list])
sock.send(data.encode())

res = json.loads(sock.recv(1024).decode())
print(res)

sock.close()

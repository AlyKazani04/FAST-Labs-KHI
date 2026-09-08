import json
import socket as s


class StudentData:
    def __init__(self):
        self.filename = "student.json"

    def process_data(self, data):
        with open(self.filename, "w") as f:
            json.dump(data, f, indent=4)

        with open(self.filename, "r") as f:
            saved_data = json.load(f)

        return saved_data

    def generate_display(self, data):
        display = f"Student ID:\t{data['student_id']}\n"
        display += f"Name:\t\t{data['name']}\n"
        display += f"Department:\t{data['department']}\n"
        display += f"Semester:\t{data['semester']}\n"
        display += f"GPA:\t\t{data['gpa']}\n"
        return display


sock = s.socket()

PORT = 3001
sock.bind(("localhost", PORT))

sock.listen(1)
print(f"Server is up and running at port {PORT}")

conn, addr = sock.accept()
print(f"Client connected at {addr[0]}:{addr[1]}!")

msg = conn.recv(1024).decode()
student = json.loads(msg)

st_data = StudentData()

saved_student = st_data.process_data(student)
display_msg = st_data.generate_display(saved_student)

conn.send(display_msg.encode())

conn.close()
sock.close()

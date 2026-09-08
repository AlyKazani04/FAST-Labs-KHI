import json
import socket as s

letter_grades = {
    "A+": 4.00,
    "A": 4.00,
    "A-": 3.67,
    "B+": 3.33,
    "B": 3.00,
    "B-": 2.67,
    "C+": 2.33,
    "C": 2.00,
    "C-": 1.67,
    "D+": 1.33,
    "D": 1.00,
    "F": 0.00,
}


class GPAData:
    def __init__(self):
        self.sgpa = 0
        self.total_credithr = 0
        self.total_quality_pts = 0

    def calculate(self, data):
        total_g = 0
        for course in data:
            total_g += letter_grades[course["grade"]]
            self.total_credithr += course["hours"]
            course["quality_points"] = course["hours"] * letter_grades[course["grade"]]
            self.total_quality_pts += course["quality_points"]
        self.sgpa = float(self.total_quality_pts / self.total_credithr)

    def generate_report(self, data):
        report = f"Course\tCH\tGrade\tGP\tQuality Points\n{'-' * 50}\n"

        for course in data:
            report += f"{course['name']}\t{course['hours']}\t{course['grade']}\t{letter_grades[course['grade']]}\t{course['quality_points']}\n"
        report += f"{'-' * 50}\n"
        report += f"Total\t{self.total_credithr}\t\t\t{self.total_quality_pts:.2f}\n"
        report += f"Semester GPA: {self.sgpa:.2f}"

        return report


sock = s.socket()

PORT = 3001
sock.bind(("localhost", PORT))

sock.listen(1)
print(f"Server is up and running at port {PORT}")

conn, addr = sock.accept()
print(f"Client connected at {addr[0]}:{addr[1]}!")

msg = conn.recv(1024).decode()
semester = json.loads(msg)

gpa = GPAData()

gpa.calculate(semester)
report = gpa.generate_report(semester)

conn.send(report.encode())

conn.close()
sock.close()

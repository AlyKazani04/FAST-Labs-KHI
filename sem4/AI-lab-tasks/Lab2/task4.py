class Employee:
    def work(self):
        print("Working")

class Manager(Employee):
    def work(self):
        print("Managing")

class Developer(Employee):
    def work(self):
        print("Developing")

class Designer(Employee):
    def work(self):
        print("Designing")

employee_list = [Employee(), Manager(), Developer(), Designer()]

for e in employee_list:
    e.work()
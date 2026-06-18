class Student:
    def __init__(self, name):
        self.name = name
        self.__grade = float()
    
    def set_grade(self, grade : float):
        self.__grade = grade

    def get_grade(self):
        return self.__grade
    
    def display_info(self):
        print(f"Name: {self.name}\nGrade: {self.get_grade()}")

std = Student("Aly")
std.set_grade(4.0)

std.display_info()
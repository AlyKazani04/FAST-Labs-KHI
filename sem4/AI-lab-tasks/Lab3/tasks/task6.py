
class Building:
    def __init__(self):
        self.layout = [
            { "a" : " ", "b" : " ", "c" : "🔥" },
            { "d" : " ", "e" : "🔥", "f" : " " },
            { "g" : " ", "h" : " ", "j" : "🔥" }
        ]
    
    def display(self):
        for row in self.layout:
            rooms = list(row.values())
            print(f"[ {rooms[0]} | {rooms[1]} | {rooms[2]} ]")

class FireFighterBot:
    def __init__(self, env: Building):
        self.__env = env
    
    def extinguish(self):
        for rowindex in range(len(self.__env.layout)):
            row = self.__env.layout[rowindex]
            for room in row:
                if row[room] == "🔥":
                    print(f"Fire detected in Room {room}. Extinguishing...")
                    row[room] = " "
                else:
                    print(f"Room {room} is safe.")
                self.__env.display()
                    


b = Building()
fbot = FireFighterBot(b)

print("Initial Building Environment: ")
b.display()
print()
fbot.extinguish()
print()
print("Final Building Environment: ")
b.display()
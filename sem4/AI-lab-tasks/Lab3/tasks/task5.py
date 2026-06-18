import random

class HospitalEnvironment:
    def __init__(self):
        self.layout = {
            "Corridor A" : ["Storage", "Station", "Room 101", "Room 102"],
            "Storage" : ["Corridor A"],
            "Station" : ["Corridor A", "Corridor B"],
            "Room 101" : ["Corridor A"],
            "Room 102" : ["Corridor A"],
            "Corridor B" : ["Storage", "Station", "Room 201", "Room 202"],
            "Room 201" : ["Corridor B"],
            "Room 202" : ["Corridor B"],
        }
        self.patient_status = random.choice(["stable", "critical"])
        self.staff_availability = True
    
    def update_env(self):
        self.patient_status = random.choice(["stable", "critical"])
        self.staff_availability = random.choice([True, False])

class DeliveryBot:
    def __init__(self, env: HospitalEnvironment):
        self.env = env
        self.curr_location = "Storage"
        self.medicine: list[tuple] = []
    
    def move(self, dest: str):
        while dest != self.curr_location:
            self.curr_location = dest if dest in self.env.layout[self.curr_location] else random.choice(self.env.layout[self.curr_location])
            print(f"Moving to {self.curr_location}...")
            if "Room" in self.curr_location and self.medicine:
                self.scan_patient_id(self.medicine[0][0], self.medicine[0][1])
            self.env.update_env()

    def pick_medicine(self, med, patient_id, room):
        if self.curr_location == "Storage":
            print(f"Picking up {med} for patient {patient_id}.")
            self.medicine.append((patient_id, room, med))
        else:
            print("Cannot pick up medicine: Not at Storage.")

    def scan_patient_id(self, patient_id, room):
        print(f"Scanning for patient ID: {patient_id}")
        if self.curr_location != room:
            print("Error: Not at the correct room.")
            return False
        return True
    
    def deliver_medicine(self, patient_id):
        for item in self.medicine:
            if item[0] == patient_id:
                print(f"Delivered {item[2]} to patient {patient_id} at {self.curr_location}")
                self.medicine.remove(item)
                return
    
    def alert_staff(self, message):
        if self.env.staff_availability:
            print(f"Alert : {message}")
        else:
            at = self.curr_location
            self.move("Station")
            print(f"Alert : {message} at {at}")
        
    def process_schedule(self, schedule):
        current_time = 0

        while schedule:
            current_time += 1
            print(f"\n--- Time: {current_time} ---")

            due_tasks = [t for t in schedule if t["time"] == current_time]

            if due_tasks:
                if self.curr_location != "Storage":
                    self.move("Storage")

                for task in due_tasks:
                    self.pick_medicine(task["medicine"], task["patient_id"], task["room"])

            for (patient_id, room, _) in self.medicine:
                self.move(room)

                if room == self.curr_location:
                    self.deliver_medicine(patient_id)
                    
                if self.env.patient_status == "critical":
                    self.alert_staff(f"Patient {patient_id} is critical")

            schedule = [t for t in schedule if t["time"] > current_time]

env = HospitalEnvironment()
bot = DeliveryBot(env)

schedule = [
    {"time": 1, "patient_id": "P1", "room": "Room 101", "medicine": "Aspirin"},
    {"time": 2, "patient_id": "P2", "room": "Room 201", "medicine": "Insulin"},
    {"time": 3, "patient_id": "P3", "room": "Room 102", "medicine": "Paracetamol"}
]

bot.process_schedule(schedule)
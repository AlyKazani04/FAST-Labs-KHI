class SecurityAgent:
    def __init__(self, id, name, status):
        self._agent_id = id
        self._name = name
        self._status = status
        
        self.display()
    
    def display(self):
        print("ID:", self._agent_id)
        print("Agent Name:", self._name)
        print("Status:", self._status)

class FireWallAgent(SecurityAgent):
    def __init__(self, id, name, status):
        super().__init__(id, name, status)

    def monitor_traffic(self):
        print("Monitoring Traffic")

class MalwareDetectionAgent(SecurityAgent):
    def __init__(self, id, name, status):
        super().__init__(id, name, status)

    def scan_files(self):
        print("Scanning Files")

class AutomationAgent(SecurityAgent):
    def __init__(self, id, name, status):
        super().__init__(id, name, status)

    def detect_traffic(self):
        print("Detecting Traffic")

sa = SecurityAgent(100, "Base Agent", "ON")
fwa = FireWallAgent(101, "FireAgent", "ON")
mda = MalwareDetectionAgent(102, "MalwareBot", "ON")
aa = AutomationAgent(103, "Autobot", "ON")

print()
fwa.monitor_traffic()
print()
mda.scan_files()
print()
aa.detect_traffic()

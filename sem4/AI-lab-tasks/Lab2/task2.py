class Threat:
    def __init__(self, id, name, sev):
        self._threat_id = id
        self._name = name
        self._severity = sev

        self.display()
    
    def display(self):
        print("ID:", self._threat_id)
        print("Threat Name:", self._name)
        print("Severity:", self._severity)

class PhishingThreat(Threat):
    def __init__(self, id, name, sev):
        super().__init__(id, name, sev)
    
    def analyze_email(self):
        print("Analyzing Emails")

class RansomwareThreat(Threat):
    def __init__(self, id, name, sev):
        super().__init__(id, name, sev)

    def scan_files(self):
        print("Scanning Files")

class BotnetThreat(Threat):
    def __init__(self, id, name, sev):
        super().__init__(id, name, sev)
    
    def detect_traffic(self):
        print("Monitoring Network Traffic")

t = Threat(100, "Base Threat", "Minimal")
print()
pt = PhishingThreat(101, "Phish Threat", "Moderate")
print()
rt = RansomwareThreat(102, "Ransom Threat", "High")
print()
bt = BotnetThreat(103, "BotNet Threat", "Critical")
print()

pt.analyze_email()
print()
rt.scan_files()
print()
bt.detect_traffic()
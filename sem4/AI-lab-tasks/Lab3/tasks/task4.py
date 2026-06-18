import random

class SystemEnvironment:
    def __init__(self):
        self.__components = [
             { "A": random.choice(["safe", "low risk", "high risk"]) },
             { "B": random.choice(["safe", "low risk", "high risk"]) },
             { "C": random.choice(["safe", "low risk", "high risk"]) },
             { "D": random.choice(["safe", "low risk", "high risk"]) },
             { "E": random.choice(["safe", "low risk", "high risk"]) },
             { "F": random.choice(["safe", "low risk", "high risk"]) },
             { "G": random.choice(["safe", "low risk", "high risk"]) },
             { "H": random.choice(["safe", "low risk", "high risk"]) },
             { "I": random.choice(["safe", "low risk", "high risk"]) }
        ]
        print("Initial System Environment:")
        self.display_components()

    def display_components(self):
        for component in self.__components:
            id = list(component.keys())[0]
            status = component[id]
            print(f"Component {id} Status: {status}")

    def get_components(self):
        return self.__components
    
class SecurityAgent:
    def __init__(self, premium=False):
        self.__ispremium = premium

    def analyze_environment(self, env: SystemEnvironment):
        print("\nAnalyzing System Environment...")
        for component in env.get_components():
            id = list(component.keys())[0]
            stat = component[id]

            if stat == "high risk":
                print(f"[CRITICAL] Component {id} Status is HIGH RISK. " + ("Immediate action required.(FREE VER)" if not self.__ispremium else "Can Patch Immediately.(PREMIUM)"))
            elif stat == "low risk":
                print(f"[WARNING] Component {id} Status is LOW RISK. Can Patch Safely.")
            else:
                print(f"[SUCCESS] Component {id} Status is SAFE. No action needed.")
            
    def utility(self, component_status: str):
        if component_status == "high risk":
            return 10 if self.__ispremium else 0
        elif component_status == "low risk":
            return 5
        else:
            return 0
    
    def patch_vulnerabilities(self, env: SystemEnvironment):
        print("\nPatching Vulnerabilities...")
        for component in env.get_components():
            patch_value = 0
            id = list(component.keys())[0]
            stat = component[id]

            patch_value = self.utility(stat)
            no_action = 0
            action = max(no_action, patch_value)

            if action > 0:
                component[id] = "safe"
                print(f"[PATCHED] Component {id} has been patched. Status: SAFE")
            else:
                print(f"[SKIPPED] Component {id} was not patched. Reason: " + (f"Status: {stat}" if stat != "high risk" else (f"Requires Premium Version. Status: {stat}") if not self.__ispremium else ""))

            
sa = SecurityAgent(False)
env = SystemEnvironment()

sa.analyze_environment(env)
sa.patch_vulnerabilities(env)

print("\nFinal System Environment:")
env.display_components()        
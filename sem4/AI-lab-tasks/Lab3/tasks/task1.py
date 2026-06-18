import random

class SystemEnvironment:

    def __init__(self):
        self.__components = {
            "A": random.choice(["safe", "unsafe"]),
            "B": random.choice(["safe", "unsafe"]),
            "C": random.choice(["safe", "unsafe"]),
            "D": random.choice(["safe", "unsafe"]),
            "E": random.choice(["safe", "unsafe"]),
            "F": random.choice(["safe", "unsafe"]),
            "G": random.choice(["safe", "unsafe"]),
            "H": random.choice(["safe", "unsafe"]),
            "I": random.choice(["safe", "unsafe"])
        }
        print("Initial System Environment:")
        self.display_components()

    def get_components(self):
        return self.__components

    def display_components(self):
        for c in self.__components:
            print(f"Component {c} Status: {self.__components[c]}")

class SecurityAgent:
    def analyze_environment(self, env: SystemEnvironment):
        patch_list = []
        print("\nAnalyzing System Environment...")
        for c in env.get_components():
            status = env.get_components()[c]
            if status == "unsafe":
                patch_list.append(c)
                print(f"[WARNING] Component {c} Status is UNSAFE. Adding to patch list.")
            else:
                print(f"[SUCCESS] Component {c} Status is SAFE. No action needed.")
        return patch_list
    
    def apply_patches(self, env: SystemEnvironment, patch_list: list):
        print("\nApplying patches to unsafe components...")
        for c in patch_list:
            env.get_components()[c] = "safe"
            print(f"[PATCHED] Component {c} has been patched. Status: SAFE")

    
sa = SecurityAgent()
env = SystemEnvironment()

patches_needed = sa.analyze_environment(env)

if patches_needed:
    sa.apply_patches(env, patches_needed)
else:
    print("\nAll components are safe - no patches needed.")

print("\nFinal System Check:")
env.display_components()
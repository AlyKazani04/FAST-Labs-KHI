import random

class Environment:
    def __init__(self, init_state:str = "dirty"):
        self.__state = init_state

    def get_percept(self):
        self.__state = random.choice(["clean", "dirty"])
        return self.__state
    
    def clean_room(self):
        self.__state = 'clean'
        print("Room is being cleaned")

class SimpleReflexAgent:
    def act(self, percept):
        if percept == "dirty":
            return "Clean the room"
        else:
            return "Room is already clean"

def run_agent(agent: SimpleReflexAgent, env: Environment, steps: int = 5):
    for s in range(steps):
        percept = env.get_percept()
        act = agent.act(percept)
        print(f"Step {s+1} | Percept : {percept} | Action : {act}")

        if percept == 'dirty':
            env.clean_room()

a = SimpleReflexAgent()
e = Environment(random.choice(["clean", "dirty"]))

run_agent(a, e)
class GoalBasedAgent:
    def __init__(self, limit: int):
        self.limit: int = limit
        print(f"Agent Created with Depth Limit: {self.limit}.")

    def dls(self, graph, node, goal, depth=0, visited=None):
        if visited is None:
            visited = set()

        visited.add(node)
        print(f"Visiting: {node}")
        if node == goal:
            return True

        if depth == self.limit:
            print("Depth Limit Reached Returning!")
            return False

        for neighbor in graph[node]:
            if self.dls(graph, neighbor, goal, depth + 1, visited):
                return True
        return False


def run_agent(agent: GoalBasedAgent, graph: dict, start_node: str, goal: str):
    if agent.dls(graph, start_node, goal):
        print(f"Found Node: {goal}!")
        return
    print("Node Not Found!")


graph = {
    "A": ["B", "C"],
    "B": ["D", "E", "A"],  # loop
    "C": ["F", "G"],
    "D": ["H"],
    "E": ["A"],
    "F": ["I"],
    "G": [],
    "H": [],
    "I": [],
}

gba = GoalBasedAgent(2)

start_node = "A"
goal = "G"
print(f"Goal: {goal}")
run_agent(gba, graph, start_node, goal)

print()

start_node = "A"
goal = "I"
print(f"Goal: {goal}")
run_agent(gba, graph, start_node, goal)


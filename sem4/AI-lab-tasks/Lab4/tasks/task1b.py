class UtilBasedAgent:
    def __init__(self, goal):
        self.goal = goal

    def utility(self, cost):
        return -cost

    def select_best(self, states):
        states.sort(key=lambda x: self.utility(x[0]), reverse=True)
        return states.pop(0)

    def ucs(self, graph, start):
        pq = [(0, start, [start])]
        visited = set()

        while pq:
            pq.sort(key=lambda x: x[0])
            cost, node, path = self.select_best(pq)

            if node in visited:
                continue

            visited.add(node)
            print(f"visiting: {node}, Total Cost: {cost}")

            if node == self.goal:
                return path, cost

            for neighbor, edgecost in graph.get(node, []):
                if neighbor not in visited:
                    total_cost = cost + edgecost
                    pq.append((total_cost, neighbor, path + [neighbor]))

        return None, float("inf")


def run_agent(agent, graph, start):
    path, cost = agent.ucs(graph, start)
    print(f"Path: {path}\nTotal Cost: {cost}")


graph = {
    "A": [("B", 1), ("C", 4)],
    "B": [("D", 2), ("E", 5)],
    "C": [("F", 1)],
    "D": [],
    "E": [],
    "F": [],
}

uba = UtilBasedAgent("F")
run_agent(uba, graph, "A")

import random


def update_edge_costs(graph, change_probability=0.2):
    for node in graph:
        for neighbor in graph[node]:
            if random.random() < change_probability:
                graph[node][neighbor] = random.randint(1, 10)
    print(f"Updated Edge Costs: {graph}\n")


def reconstruct_path(came_from, current):
    path = []
    while current is not None:
        path.append(current)
        current = came_from[current]
    return path[::-1]


def dynamic_a_star(graph, start, goal, heuristic):

    frontier = []
    frontier.append((start, heuristic[start]))

    g_costs = {start: 0}
    came_from = {start: None}

    while frontier:
        frontier.sort(key=lambda x: x[1])
        current_node, current_f = frontier.pop(0)

        if current_node == goal:
            path = reconstruct_path(came_from, current_node)
            print("\nGoal found. Optimal Path:", path)
            print("Total Cost:", g_costs[goal])
            return path

        update_edge_costs(graph)

        for neighbor, cost in graph[current_node].items():
            new_g = g_costs[current_node] + cost

            if neighbor not in g_costs or new_g < g_costs[neighbor]:
                g_costs[neighbor] = new_g
                came_from[neighbor] = current_node

                f_cost = new_g + heuristic[neighbor]

                frontier.append((neighbor, f_cost))

    print("Goal not found")
    return None


graph = {
    "A": {"B": 4, "C": 3},
    "B": {"E": 12, "F": 5},
    "C": {"D": 7, "E": 10},
    "D": {"E": 2},
    "E": {"G": 5},
    "F": {"G": 16},
    "G": {},
}
heuristic = {"A": 14, "B": 12, "C": 11, "D": 6, "E": 4, "F": 11, "G": 0}

print("\nFollowing is the A* Search:")
dynamic_a_star(graph, "A", "G", heuristic)

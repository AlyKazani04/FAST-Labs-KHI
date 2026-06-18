graph = {
    'S': {'A': 3, 'B': 6, 'C': 5},
    'A': {'D': 9, 'E': 8},
    'B': {'F': 12, 'G': 14},
    'C': {'H': 7},
    'H': {'I': 5, 'J': 6},
    'I': {'K': 1, 'L': 10, 'M': 2},
    'D': {}, 'E': {}, 'F': {}, 'G': {},
    'J': {}, 'K': {}, 'L': {}, 'M': {}
}

heuristic = {
    'S': 10, 'A': 9, 'B': 7, 'C': 5, 'D': 8, 'E': 6, 'F': 4, 'G': 3,
    'H': 3, 'I': 2, 'J': 6, 'K': 2, 'L': 0, 'M': 1
}

def hill_climbing(graph, start, goal):
    current_node = start
    path = [current_node]

    while current_node != goal:
        neighbors = graph.get(current_node, [])
        if not neighbors:
            print("No path found with Hill Climbing.")
            return None

        # Choose the best neighbor based on the heuristic (lowest value)
        best_neighbor = min(neighbors, key=lambda x: heuristic[x[0]])
        best_neighbor_node = best_neighbor[0]

        # If the best neighbor is worse than the current node, stop (local maximum)
        if heuristic[best_neighbor_node] >= heuristic[current_node]:
            print("Stuck at local maximum. No path found with Hill Climbing.")
            return None

        current_node = best_neighbor_node
        path.append(current_node)

        if current_node == goal:
            print(f"Goal found with Hill Climbing. Path: {path}")
            return path

    print("Goal not found.")
    return None

hill_climbing(graph, 'S', 'L')
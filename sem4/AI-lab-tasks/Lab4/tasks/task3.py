def dls(graph, node, goal, depth, path):
    if depth == 0:
        return False
    if node == goal:
        path.append(node)
        return True
    if node not in graph:
        return False
    for child in graph[node]:
        if dls(graph, child, goal, depth - 1, path):
            path.append(node)
            return True
    return False


def iterative_deepening(graph, start, goal, max_depth=10):
    for depth in range(max_depth + 1):
        print(f"Depth: {depth}")
        path = []
        if dls(graph, start, goal, depth, path):
            print("\nPath to goal:", "->".join(reversed(path)))
            return
    print("Goal not found within depth limit.")


tree = {
    "A": ["B", "C"],
    "B": ["D", "E"],
    "C": ["F", "G"],
    "D": ["H"],
    "E": [],
    "F": ["I"],
    "G": [],
    "H": [],
    "I": [],
}

graph = {
    "Corridor A": ["Storage", "Station", "Room 101", "Room 102"],
    "Storage": ["Corridor A"],
    "Station": ["Corridor A", "Corridor B"],
    "Room 101": ["Corridor A"],
    "Room 102": ["Corridor A"],
    "Corridor B": ["Storage", "Station", "Room 201", "Room 202"],
    "Room 201": ["Corridor B"],
    "Room 202": ["Corridor B"],
}


print("Iterative Deepening on Tree: ")
iterative_deepening(tree, "A", "I")

print("\nIterative Deepening on Graph: ")
iterative_deepening(graph, "Corridor A", "Room 202")

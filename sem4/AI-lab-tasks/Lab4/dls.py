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


def dls(graph, node, goal, depth=0, limit=3, visited=None):
    if visited is None:
        visited = set()

    visited.add(node)
    print(f"Visiting: {node}")
    if node == goal:
        return True

    if depth == limit:
        print("Depth Limit Reached Returning!")
        return False

    for neighbor in graph[node]:
        if dls(graph, neighbor, goal, depth + 1, limit, visited):
            return True
    return False


dls(tree, "A", goal="I", depth=0, limit=4)


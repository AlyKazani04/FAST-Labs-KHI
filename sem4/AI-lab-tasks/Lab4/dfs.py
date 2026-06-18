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


def dfs(tree, start, goal):
    stack = []
    visited = []
    stack.append(start)
    visited.append(start)

    while stack:
        node = stack.pop()
        print(node, end=" ")

        if goal == node:
            print(f"Goal Reached! {node}")
            break

        for neighbor in reversed(tree[node]):
            if neighbor not in visited:
                visited.append(neighbor)
                stack.append(neighbor)


dfs(tree, start="A", goal="G")

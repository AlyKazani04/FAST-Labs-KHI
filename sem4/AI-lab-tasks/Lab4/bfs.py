tree = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F', 'G'],
    'D': ['H'],
    'E': [],
    'F': ['I'],
    'G': [],
    'H': [],
    'I': []
}

def bfs(tree, start, goal):
    queue = []
    visited = []
    visited.append(start)
    queue.append(start)

    while queue:
        node = queue.pop(0)
        print(node, end=' ')
        if node == goal:
            print("Goal!")
            break
        for neighbor in tree[node]:
            if neighbor not in visited:
                visited.append(neighbor)
                queue.append(neighbor)

bfs(tree, 'A', 'I')
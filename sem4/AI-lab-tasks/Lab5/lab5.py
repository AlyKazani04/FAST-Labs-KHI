def best_first_search(graph, start, goal):
    visited = set()
    pq = [(0, start)]
    
    while pq:
        cost, node = pq.pop(0)
        if node not in visited:
            print(node, end=" ")
            visited.add(node)

        if node == goal:
            print("Goal Reached!\n")
            return True

        for neighbor, weight in graph[node]:
            if neighbor not in visited:
                pq.append((weight, neighbor))
                pq.sort(key=lambda x: x[0])

    print("Goal Not Reachable!")
    return False

graph = {
    'S': [('A', 3), ('B', 6), ('C', 5)],
    'A': [('D', 9), ('E', 8)],
    'B': [('F', 12), ('G', 14)],
    'C': [('H', 7)],
    'H': [('I', 5), ('J', 6)],
    'I': [('K', 1), ('L', 10), ('M', 2)],
    'D': [],
    'E': [],
    'F': [],
    'G': [],
    'J': [],
    'K': [],
    'L': [],
    'M': []
}

print("Best-First Search Path:")
best_first_search(graph, 'S', 'I')
graph = {
    "1": [("2", 10), ("3", 15), ("4", 20)],
    "2": [("1", 10), ("3", 35), ("4", 25)],
    "3": [("1", 15), ("2", 35), ("4", 30)],
    "4": [("1", 20), ("2", 25), ("3", 30)],
}


def travelling_salesman(graph, start):
    # (cost, curr, visited_set, path)
    pq = [(0, start, {start}, [start])]
    n = len(graph)

    while pq:
        pq.sort(key=lambda x: x[0])
        cost, node, visited, path = pq.pop(0)

        if len(visited) == n:
            for neighbor, edgecost in graph[node]:
                if start == neighbor:
                    return cost + edgecost, path + [start]

        for neighbor, edgecost in graph[node]:
            if neighbor not in visited:
                new_cost = cost + edgecost
                new_visited = visited | {neighbor}
                pq.append((new_cost, neighbor, new_visited, path + [neighbor]))

    return None, None


start = "1"
cost, path = travelling_salesman(graph, start)
print(f"Cost: {cost}\nPath: {path}")

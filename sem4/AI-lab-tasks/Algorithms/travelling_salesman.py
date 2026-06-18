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

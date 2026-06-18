def utility(cost):
    return -cost


def select_best(states):
    states.sort(key=lambda x: utility(x[0]), reverse=True)
    return states.pop(0)


def ucs(graph, start, goal):
    pq = [(0, start, [start])]
    visited = set()

    while pq:
        pq.sort(key=lambda x: x[0])
        cost, node, path = select_best(pq)

        if node in visited:
            continue

        visited.add(node)
        print(f"visiting: {node}, Total Cost: {cost}")

        if node == goal:
            return path, cost

        for neighbor, edgecost in graph.get(node, []):
            if neighbor not in visited:
                total_cost = cost + edgecost
                pq.append((total_cost, neighbor, path + [neighbor]))

    return None, float("inf")

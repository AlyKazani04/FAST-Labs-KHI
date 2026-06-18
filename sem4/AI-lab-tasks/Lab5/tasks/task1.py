class Node:
    def __init__(self, position, parent=None):
        self.position = position
        self.parent = parent
        self.g = 0
        self.h = 0
        self.f = 0


def heuristic(current_pos, end_pos):
    # Manhattan distance
    return abs(current_pos[0] - end_pos[0]) + abs(current_pos[1] - end_pos[1])


def best_first_search(maze, start, end):
    rows = len(maze)
    cols = len(maze[0])

    start_node = Node(start)

    frontier = []
    frontier.append(start_node)

    visited = set()

    while len(frontier) > 0:
        frontier.sort(key=lambda node: node.f)

        current_node = frontier.pop(0)
        current_pos = current_node.position

        if current_pos == end:
            path = []
            while current_node:
                path.append(current_node.position)
                current_node = current_node.parent
            return path[::-1], current_pos

        visited.add(current_pos)

        # (Down, Up, Right, Left)
        for dx, dy in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
            new_pos = (current_pos[0] + dx, current_pos[1] + dy)

            if 0 <= new_pos[0] < rows and 0 <= new_pos[1] < cols:
                if maze[new_pos[0]][new_pos[1]] == 0 and new_pos not in visited:
                    new_node = Node(new_pos, current_node)

                    new_node.g = current_node.g + 1
                    new_node.h = heuristic(new_pos, end)

                    new_node.f = new_node.h

                    frontier.append(new_node)
                    visited.add(new_pos)

    return None, start


maze = [
    [0, 0, 1, 0, 0],
    [0, 0, 0, 0, 0],
    [0, 0, 1, 0, 1],
    [0, 0, 1, 0, 0],
    [0, 0, 0, 1, 0],
]
start = (0, 0)
end_goals = [(4, 4), (2, 1), (0, 0)]
for end in end_goals:
    print("Searching for:", end)
    path, pos = best_first_search(maze, start, end)
    if path:
        print("Path found:", path)
    start = end

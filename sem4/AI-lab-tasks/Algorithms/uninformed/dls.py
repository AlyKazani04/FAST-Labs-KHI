def dls(maze, pos, goal, depth=0, limit=5, path=None):
    if path is None:
        path = []

    path.append(pos)

    # row, col for list = y, x
    node = maze[pos[1]][pos[0]]

    if node == goal:
        return True, path

    if depth == limit or node == 1:
        path.pop()
        return False, path

    for dx, dy in [(1, 0), (0, 1)]:
        newX = pos[0] + dx
        newY = pos[1] + dy

        if 0 <= newX < len(maze[0]) and 0 <= newY < len(maze):
            nextSearch = (newX, newY)

            found, newPath = dls(maze, nextSearch, goal, depth + 1, limit, path)
            if found:
                return True, newPath
    path.pop()
    return False, path


maze = [["S", 0, 0, 1, 0], [1, 0, 1, 0, 0], [0, 0, 0, 0, "G"], [1, 1, 0, 1, 1]]

start = (0, 0)
pathCheck, path = dls(maze, start, "G", limit=10)
if pathCheck:
    print("Route Found!", path)
else:
    print("Path Not Found!")

# This algorithm works, but it will only yield
# results if the AI bot/dev magically guesses the optimal depth
# too low, may give false negatives,
# too high may waste processing power.

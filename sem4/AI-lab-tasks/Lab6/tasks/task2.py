import math
from typing import List, Sequence, Tuple

# Coordinate type: accepts both int and float values
Coord = Tuple[int | float, int | float]


def euclidean_distance(p1: Coord, p2: Coord) -> float:
    return math.sqrt((p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2)


def total_route_distance(route: List[int], coords: Sequence[Coord]) -> float:
    distance = 0.0
    n = len(route)
    for i in range(n):
        distance += euclidean_distance(coords[route[i]], coords[route[(i + 1) % n]])
    return distance


def hill_climbing(coords: Sequence[Coord]) -> Tuple[List[int], float]:
    n = len(coords)
    if n == 0:
        return [], 0.0
    if n == 1:
        return [0], 0.0

    current_route = list(range(n))
    current_distance = total_route_distance(current_route, coords)

    print(f"Initial route:    {current_route}")
    print(f"Initial distance: {current_distance:.4f}\n")

    improved = True
    iteration = 0

    while improved:
        improved = False
        best_route = current_route[:]
        best_distance = current_distance

        for i in range(1, n - 1):
            for j in range(i + 1, n):
                neighbour = (
                    current_route[:i]
                    + current_route[i : j + 1][::-1]
                    + current_route[j + 1 :]
                )
                neighbour_distance = total_route_distance(neighbour, coords)

                # Accept only if this neighbour is strictly better (mirrors
                # the reference: move only when heuristic improves)
                if neighbour_distance < best_distance:
                    best_route = neighbour
                    best_distance = neighbour_distance
                    improved = True

        # Move to the best improving neighbour found
        if improved:
            iteration += 1
            print(
                f"Iteration {iteration}: distance improved {current_distance:.4f} -> {best_distance:.4f}  route: {best_route}"
            )
            current_route = best_route
            current_distance = best_distance

    if not improved and iteration == 0:
        print("Already at local optimum. No improvement found.")

    return current_route, current_distance


# 1: Small delivery grid
print("1: 5 Delivery Locations (Grid)")

locations_1 = [
    (0, 0),  # Depot  (index 0)
    (2, 4),  # Stop 1 (index 1)
    (5, 2),  # Stop 2 (index 2)
    (6, 6),  # Stop 3 (index 3)
    (1, 7),  # Stop 4 (index 4)
]

optimized_route, optimized_distance = hill_climbing(locations_1)

print(f"\nOptimized route (indices): {optimized_route}")
print(f"Optimized route (coords):  {[locations_1[i] for i in optimized_route]}")
print(f"Total distance:            {optimized_distance:.4f}")

# 2: Larger to see more swaps
print()
print("2: 8 Delivery Locations")

locations_2 = [
    (0, 0),  # Depot
    (3, 1),
    (6, 4),
    (5, 8),
    (2, 9),
    (0, 5),
    (4, 6),
    (8, 2),
]

optimized_route_2, optimized_distance_2 = hill_climbing(locations_2)

print(f"\nOptimized route (indices): {optimized_route_2}")
print(f"Optimized route (coords):  {[locations_2[i] for i in optimized_route_2]}")
print(f"Total distance:            {optimized_distance_2:.4f}")

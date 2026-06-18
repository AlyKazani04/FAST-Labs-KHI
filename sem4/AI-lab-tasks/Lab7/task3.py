from ortools.sat.python import cp_model

CITIES = {
    0: ("New York", 0, 0),
    1: ("Los Angeles", 28, 8),
    2: ("Chicago", 13, 5),
    3: ("Houston", 18, 20),
    4: ("Phoenix", 22, 14),
    5: ("Philadelphia", 3, 2),
    6: ("San Antonio", 19, 22),
    7: ("San Diego", 26, 10),
    8: ("Dallas", 17, 18),
    9: ("San Jose", 25, 5),
}

NUM_CITIES = len(CITIES)


def build_distance_matrix():
    # Scaled by 100 — CP-SAT requires integer coefficients
    dist = {}
    for i in range(NUM_CITIES):
        for j in range(NUM_CITIES):
            x1, y1 = CITIES[i][1], CITIES[i][2]
            x2, y2 = CITIES[j][1], CITIES[j][2]
            dist[(i, j)] = int(((x2 - x1) ** 2 + (y2 - y1) ** 2) ** 0.5 * 100)
    return dist


def print_overview():
    print("  TRAVELLING SALESMAN PROBLEM — CP-SAT Formulation")
    print()
    print(f"  Cities     : {NUM_CITIES}")
    print(f"  Start/End  : {CITIES[0][0]} (index 0)")
    print("\n  CSP Definition")
    print("=" * 55)
    print("  Variables   : position[0..9] — city at each step")
    print("  Domains     : {0, 1, ..., 9} per variable")
    print("  Constraints :")
    print("    1. AllDifferent  — no city repeated")
    print("    2. position[0]   — fixed to start city (0)")
    print("    3. Minimize      — total Euclidean distance")
    print("=" * 55)


def solve_tsp(dist):
    model = cp_model.CpModel()

    # Variables
    # position[i] = which city is visited at step i
    position = [
        model.new_int_var(0, NUM_CITIES - 1, f"pos_{i}") for i in range(NUM_CITIES)
    ]

    # arc[i][j] = 1 if city j is visited directly after city i
    arc = {
        (i, j): model.new_bool_var(f"arc_{i}_{j}")
        for i in range(NUM_CITIES)
        for j in range(NUM_CITIES)
        if i != j
    }

    # Constraints:
    # Each city visited exactly once
    model.add_all_different(position)

    # Fix start to city 0
    model.add(position[0] == 0)

    # Each city has exactly one successor and one predecessor
    for i in range(NUM_CITIES):
        model.add(sum(arc[(i, j)] for j in range(NUM_CITIES) if i != j) == 1)
        model.add(sum(arc[(j, i)] for j in range(NUM_CITIES) if i != j) == 1)

    # Circuit constraint — ensures a single closed tour (no subtours)
    model.add_circuit(
        [
            (i, j, arc[(i, j)])
            for i in range(NUM_CITIES)
            for j in range(NUM_CITIES)
            if i != j
        ]
    )

    # Objective
    total_distance = sum(dist[(i, j)] * arc[(i, j)] for i, j in arc)
    model.minimize(total_distance)

    # Solve
    solver = cp_model.CpSolver()
    solver.parameters.max_time_in_seconds = 10.0
    status = solver.solve(model)

    return solver, status, arc


def print_solution(solver, status, arc, dist):
    if status not in (cp_model.OPTIMAL, cp_model.FEASIBLE):
        print("  No solution found.")
        return

    # Reconstruct tour from arc variables
    next_city = {i: j for (i, j) in arc if solver.value(arc[(i, j)]) == 1}

    tour = [0]
    while len(tour) < NUM_CITIES:
        tour.append(next_city[tour[-1]])

    total = 0
    print(f"\n  Status : {solver.status_name(status)}")
    print("\n  OPTIMAL TOUR")
    print("  -------------------------------------------------")
    for step in range(NUM_CITIES):
        current = tour[step]
        nxt = tour[(step + 1) % NUM_CITIES]
        leg = dist[(current, nxt)] / 100
        total += leg
        print(
            f"  Step {step + 1:>2}: {CITIES[current][0]:<15} → {CITIES[nxt][0]:<15}  dist: {leg:.2f}"
        )
    print("  -------------------------------------------------")
    print()
    print(f"  Total distance : {total:.2f} units")
    route_names = " → ".join(CITIES[c][0] for c in tour) + f" → {CITIES[tour[0]][0]}"
    print(f"  Route : {route_names}")


if __name__ == "__main__":
    print_overview()
    dist = build_distance_matrix()
    solver, status, arc = solve_tsp(dist)
    print_solution(solver, status, arc, dist)

from ortools.sat.python import cp_model
from collections import deque


GRID = [
    [0, 1, 1, 0, 0, 0, 1, 1],
    [0, 1, 1, 1, 0, 0, 1, 0],
    [0, 0, 1, 1, 1, 0, 0, 0],
    [0, 0, 0, 1, 0, 0, 0, 0],
    [1, 1, 0, 0, 0, 1, 1, 1],
    [1, 1, 1, 0, 0, 1, 0, 1],
    [0, 1, 0, 0, 0, 1, 1, 1],
    [0, 0, 0, 1, 1, 0, 0, 0],
]

ROWS = len(GRID)
COLS = len(GRID[0])
DIRECTIONS = [(-1, 0), (1, 0), (0, -1), (0, 1)]  # up, down, left, right


def build_csp_model(grid):
    model = cp_model.CpModel()

    # Create one BoolVar per cell
    cell_vars = [
        [model.new_bool_var(f"cell_{r}_{c}") for c in range(COLS)] for r in range(ROWS)
    ]

    # Constraint: each variable must equal its observed satellite value
    for r in range(ROWS):
        for c in range(COLS):
            if grid[r][c] == 1:
                model.add(cell_vars[r][c] == 1)
            else:
                model.add(cell_vars[r][c] == 0)

    # Solve
    solver = cp_model.CpSolver()
    status = solver.solve(model)

    return model, solver, cell_vars, status


def find_all_islands(grid):
    visited = [[False] * COLS for _ in range(ROWS)]
    islands = []

    for r in range(ROWS):
        for c in range(COLS):
            if grid[r][c] == 1 and not visited[r][c]:
                # BFS to collect all connected land cells
                island = set()
                queue = deque([(r, c)])
                visited[r][c] = True
                while queue:
                    cr, cc = queue.popleft()
                    island.add((cr, cc))
                    for dr, dc in DIRECTIONS:
                        nr, nc = cr + dr, cc + dc
                        if (
                            0 <= nr < ROWS
                            and 0 <= nc < COLS
                            and grid[nr][nc] == 1
                            and not visited[nr][nc]
                        ):
                            visited[nr][nc] = True
                            queue.append((nr, nc))
                islands.append(island)

    return islands


def compute_perimeter(island, solver, cell_vars):
    perimeter = 0
    boundary_edges = []

    for r, c in island:
        for dr, dc in DIRECTIONS:
            nr, nc = r + dr, c + dc
            # Edge is a boundary if neighbor is out-of-bounds OR is water (CSP var = 0)
            if not (0 <= nr < ROWS and 0 <= nc < COLS):
                perimeter += 1
                boundary_edges.append(((r, c), (nr, nc), "grid-border"))
            elif solver.value(cell_vars[nr][nc]) == 0:
                perimeter += 1
                boundary_edges.append(((r, c), (nr, nc), "water-border"))

    return perimeter, boundary_edges


def print_grid_highlighted(grid, highlight_cells, label="Grid"):
    print(f"  {label}\n")
    for r in range(ROWS):
        row_str = "  "
        for c in range(COLS):
            if (r, c) in highlight_cells:
                row_str += f"[{grid[r][c]}]"
            else:
                row_str += f" {grid[r][c]} "
        print(row_str)


def print_section(title):
    print(f"  {title}\n")


#  Main
def main():
    print_section("SATELLITE ISLAND EROSION TRACKER")
    print(f"  Grid dimensions : {ROWS} × {COLS}")
    print(f"  Total cells     : {ROWS * COLS}")
    land_count = sum(GRID[r][c] for r in range(ROWS) for c in range(COLS))
    print(f"  Land cells      : {land_count}")
    print(f"  Water cells     : {ROWS * COLS - land_count}")

    # Step 1: Build & solve CSP model
    print_section("\nCSP Model — Binary Variable Assignment")
    model, solver, cell_vars, status = build_csp_model(GRID)

    status_name = solver.status_name(status)
    print(f"  Solver status   : {status_name}")
    print(f"  Variables       : {ROWS * COLS} BoolVars")
    print(f"  Constraints     : {ROWS * COLS} equality constraints")

    if status not in (cp_model.OPTIMAL, cp_model.FEASIBLE):
        print("  CSP model is infeasible. Exiting.")
        return

    print("\n  CSP Variable Values (matches satellite grid):")
    for r in range(ROWS):
        row_vals = "  " + " ".join(
            str(solver.value(cell_vars[r][c])) for c in range(COLS)
        )
        print(row_vals)

    # Step 2: Identify all islands
    print_section("\nIsland Detection via BFS")
    islands = find_all_islands(GRID)
    print(f"  Islands found   : {len(islands)}")
    for i, island in enumerate(islands):
        print(f"    Island {i + 1:>2}     : {len(island)} cells  →  {sorted(island)}")

    largest_island = max(islands, key=len)
    print(f"\n  ★ Largest island: {len(largest_island)} cells")

    print_grid_highlighted(GRID, largest_island, label="Largest Island [highlighted]")

    # Step 3: Compute perimeter using CSP values
    print_section("\nPerimeter Computation via CSP Boundary Edges")
    perimeter, boundary_edges = compute_perimeter(largest_island, solver, cell_vars)

    grid_border_edges = [e for e in boundary_edges if e[2] == "grid-border"]
    water_border_edges = [e for e in boundary_edges if e[2] == "water-border"]

    print(f"  Total perimeter edges : {perimeter}")
    print(f"    Grid boundary    : {len(grid_border_edges)}")
    print(f"    Land↔Water edges : {len(water_border_edges)}")

    print(f"  Largest island size : {len(largest_island)} cells")
    print(f"  Perimeter           : {perimeter} units")


if __name__ == "__main__":
    main()

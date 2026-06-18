import math
from ortools.sat.python import cp_model


class Robot:
    def __init__(self, size, obstacles, start, end):
        self.size = size
        self.obstacles = set(obstacles)
        self.start = start
        self.end = end
        self.model = cp_model.CpModel()

    def solve(self):
        max_steps = self.size * self.size

        # Variables
        px = [
            self.model.NewIntVar(0, self.size - 1, f"x_{t}") for t in range(max_steps)
        ]
        py = [
            self.model.NewIntVar(0, self.size - 1, f"y_{t}") for t in range(max_steps)
        ]

        # State Constraints
        self.model.Add(px[0] == self.start[0])
        self.model.Add(py[0] == self.start[1])

        # Movement Logic
        is_moving = []
        for t in range(max_steps - 1):
            dx = self.model.NewIntVar(-1, 1, f"dx_{t}")
            dy = self.model.NewIntVar(-1, 1, f"dy_{t}")
            abs_dx = self.model.NewIntVar(0, 1, f"abs_dx_{t}")
            abs_dy = self.model.NewIntVar(0, 1, f"abs_dy_{t}")

            self.model.Add(dx == px[t + 1] - px[t])
            self.model.Add(dy == py[t + 1] - py[t])
            self.model.AddAbsEquality(abs_dx, dx)
            self.model.AddAbsEquality(abs_dy, dy)

            # Diagonal Move: |dx| == |dy|
            self.model.Add(abs_dx == abs_dy)

            # move_occurred is 1 if diagonal, 0 if staying
            move_occurred = self.model.NewBoolVar(f"move_{t}")
            self.model.Add(abs_dx == 1).OnlyEnforceIf(move_occurred)
            self.model.Add(abs_dx == 0).OnlyEnforceIf(move_occurred.Not())
            is_moving.append(move_occurred)

            if t > 0:
                self.model.AddImplication(is_moving[t].Not(), is_moving[t - 1].Not())
                # Better: If t is not moving, then t+1 cannot move
                self.model.Add(is_moving[t] <= is_moving[t - 1])

        # Obstacles & Goal
        for t in range(max_steps):
            for ox, oy in self.obstacles:
                self.model.AddForbiddenAssignments([px[t], py[t]], [(ox, oy)])

        # Reaching the goal at some point
        reaches_goal = [self.model.NewBoolVar(f"goal_{t}") for t in range(max_steps)]
        for t in range(max_steps):
            at_x = self.model.NewBoolVar(f"at_x_{t}")
            at_y = self.model.NewBoolVar(f"at_y_{t}")
            self.model.Add(px[t] == self.end[0]).OnlyEnforceIf(at_x)
            self.model.Add(py[t] == self.end[1]).OnlyEnforceIf(at_y)
            self.model.AddBoolAnd([at_x, at_y]).OnlyEnforceIf(reaches_goal[t])

        # Must reach goal at least once
        self.model.AddBoolOr(reaches_goal)

        # Minimize total diagonal moves
        self.model.Minimize(sum(is_moving))

        solver = cp_model.CpSolver()
        status = solver.Solve(self.model)

        if status in [cp_model.OPTIMAL, cp_model.FEASIBLE]:
            raw_path = []
            for t in range(max_steps):
                coord = (solver.Value(px[t]), solver.Value(py[t]))
                raw_path.append(coord)
                if coord == self.end:
                    break

            final_path = [raw_path[0]]
            for pos in raw_path[1:]:
                if pos != final_path[-1]:
                    final_path.append(pos)

            actual_steps = len(final_path) - 1
            cost = actual_steps * math.sqrt(2)

            print(f"Optimal Path: {final_path}")
            print(f"Total Steps: {actual_steps}")
            print(f"Pythagorean Cost: {cost:.4f}")
        else:
            print("No path found.")


obstacles = [(2, 2)]
robot = Robot(size=5, obstacles=obstacles, start=(1, 1), end=(4, 4))
robot.solve()

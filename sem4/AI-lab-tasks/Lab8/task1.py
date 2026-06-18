class Environment:
    def __init__(self) -> None:
        self.tree = {
            "Zone A": {"Option 1": 3, "Option 2": 5},
            "Zone B": {"Option 1": 2, "Option 2": 9},
        }

    def get_robot_moves(self):
        return list(self.tree.keys())

    def get_thief_moves(self, robot_move):
        return list(self.tree[robot_move].keys())

    def get_utility(self, robot_move, thief_move):
        return self.tree[robot_move][thief_move]


class MinimaxAgent:
    def __init__(self, environment) -> None:
        self.env = environment

    def decide_move(self):
        best_val = float("-inf")
        best_move = None

        for move in self.env.get_robot_moves():
            print(f"Robot thinking about: {move}")

            move_value = self.min_value(move)
            print(f"Outcome for {move} (after Thief's): {move_value}\n")

            if move_value > best_val:
                best_val = move_value
                best_move = move

        print(f"Result: Robot chooses {best_move} with guaranteed value of {best_val}")
        return best_move

    def min_value(self, robot_move):
        thief_options = self.env.get_thief_moves(robot_move)

        utilities = []
        for option in thief_options:
            val = self.env.get_utility(robot_move, option)

            print(f"\tThief considers {option} | Value: {val}")

            utilities.append(val)
        return min(utilities)


warehouse = Environment()
security_bot = MinimaxAgent(warehouse)

final_choice = security_bot.decide_move()

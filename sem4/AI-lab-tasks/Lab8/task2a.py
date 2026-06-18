class Environment:
    def __init__(self) -> None:
        self.tree = {
            "Stop": {"Option 1": 6, "Option 2": 7},
            "Go": {"Option 1": 2, "Option 2": 4},
            "Turn": {"Option 1": 8, "Option 2": 3},
        }

    def get_car_moves(self):
        return list(self.tree.keys())

    def get_other_car_moves(self, car_move):
        return list(self.tree[car_move].keys())

    def get_utility(self, car_move, other_car_move):
        return self.tree[car_move][other_car_move]


class MinmaxIntersection:
    def __init__(self, environment) -> None:
        self.env = environment

    def decide_move(self):
        best_move = None
        best_val = float("-inf")

        for move in self.env.get_car_moves():
            print(f"Car is analyzing: {move}")

            move_value = self.min_value(move)
            print(f"Outcome for {move} (after other car's): {move_value}\n")

            if move_value > best_val:
                best_val = move_value
                best_move = move

        print(
            f"Result: Self Driving Car chooses {best_move} with guaranteed value of {best_val}"
        )
        return best_move

    def min_value(self, car_move):
        other_car_options = self.env.get_other_car_moves(car_move)

        utilities = []
        for option in other_car_options:
            val = self.env.get_utility(car_move, option)

            print(f"\tOther car considers {option} | Value: {val}")

            utilities.append(val)
        return min(utilities)


intersection = Environment()
selfdrivingcar = MinmaxIntersection(intersection)

selfdrivingcar.decide_move()

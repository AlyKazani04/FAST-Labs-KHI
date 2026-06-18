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


class AlphaBetaIntersection:
    def __init__(self, environment):
        self.env = environment

    def decide_move(self):
        alpha = float("-inf")
        beta = float("inf")
        best_move = None
        best_val = float("-inf")

        for move in self.env.get_car_moves():
            print(f"Before MIN picked: Alpha: {alpha}, Beta: {beta}")
            val = self.min_value(move, alpha, beta)

            if val > best_val:
                best_val = val
                best_move = move

            alpha = max(alpha, best_val)
            print(f"After MIN picked {val}: Alpha: {alpha}, Beta: {beta}\n")

        print(f"Result: MAX chose '{best_move}' with value {best_val}")
        return best_move

    def min_value(self, car_move, alpha, beta):
        res_val = float("inf")
        options = self.env.get_other_car_moves(car_move)

        for opt in options:
            val = self.env.get_utility(car_move, opt)
            res_val = min(res_val, val)

            if res_val > alpha:
                beta = min(beta, res_val)

            if val <= beta:
                print(f"\tMIN picked {res_val}: Alpha: {alpha}, Beta: {beta}")
            else:
                print(f"\tMIN didn't pick {val}")

            if res_val <= alpha and opt != options[-1]:
                print(
                    f"\tPruning remaining options for {car_move} because {res_val} <= {alpha}"
                )
                return res_val

        return res_val


intersection = Environment()
agent = AlphaBetaIntersection(intersection)
agent.decide_move()

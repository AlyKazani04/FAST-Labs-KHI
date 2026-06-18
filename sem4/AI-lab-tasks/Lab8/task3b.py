tree = {
    "Attack": {
        "A1": {"option1": 5, "option2": 6},
        "A2": {"option1": 7, "option2": 4},
    },
    "Defend": {
        "D1": {"option1": 3, "option2": 8},
        "D2": {"option1": 6, "option2": 2},
    },
    "Gather": {
        "G1": {"option1": 1, "option2": 9},
        "G2": {"option1": 4, "option2": 7},
    },
}


def alpha_beta(
    curr,
    name="Root",
    alpha=float("-inf"),
    beta=float("inf"),
    maximizing_player=True,
    tabs=0,
):
    if isinstance(curr, int):
        return curr

    indent = tabs * 2 * " "

    if maximizing_player:
        best_value = float("-inf")
        best_node = None

        for key, val in curr.items():
            value = alpha_beta(val, key, alpha, beta, False, tabs + 1)

            if best_node is None:
                print(
                    f"{indent}MAX {name} starts with {key} ({value}). [{alpha}, {beta}]"
                )
                best_value = value
                best_node = key
            elif value > best_value:
                print(
                    f"{indent}MAX {name} updated to {key} ({value}) from {best_value}. [{alpha}, {beta}]"
                )
                best_value = value
                best_node = key
            else:
                print(
                    f"{indent}MAX {name} kept {best_node} ({best_value}), didn't take {key} ({value}). [{alpha}, {beta}]"
                )

            alpha = max(alpha, best_value)
            if beta <= alpha:
                print(
                    f"{indent}Pruning: MAX {name} stopped searching. [{alpha}, {beta}]"
                )
                break
        return best_value
    else:
        best_value = float("inf")
        best_node = None

        for key, val in curr.items():
            value = alpha_beta(val, key, alpha, beta, True, tabs + 1)

            if best_node is None:
                print(
                    f"{indent}MIN {name} starts with {key} ({value}). [{alpha}, {beta}]"
                )
                best_value = value
                best_node = key
            elif value < best_value:
                print(
                    f"{indent}MIN {name} updated to {key} ({value}) from {best_value}. [{alpha}, {beta}]"
                )
                best_value = value
                best_node = key
            else:
                print(
                    f"{indent}MIN {name} kept {best_node} ({best_value}), didn't take {key} ({value}). [{alpha}, {beta}]"
                )

            beta = min(beta, best_value)
            if beta <= alpha:
                print(
                    f"{indent}Pruning: MIN {name} stopped searching. [{alpha}, {beta}]"
                )
                break
        return best_value


print("[alpha, beta]")
print(f"\nResult: {alpha_beta(tree)}")

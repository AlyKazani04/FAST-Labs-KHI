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


def minmax(curr, name="Root", maximizing_player=True, tabs=0):
    if isinstance(curr, int):
        return curr

    indent = " " * tabs * 2

    if maximizing_player:
        best_value = float("-inf")
        best_node = None

        for key, val in curr.items():
            value = minmax(val, key, False, tabs + 1)
            if value > best_value:
                if best_node is None:
                    print(f"{indent}MAX {name} started with {key} ({value}).")
                else:
                    print(
                        f"{indent}MAX {name} updated to {value} from {best_value} because of {key} ({value})."
                    )
                best_value = value
                best_node = name
            else:
                print(
                    f"{indent}MAX {name} kept {best_value}, didn't pick {key} ({value})."
                )

        return best_value
    else:
        best_value = float("inf")
        best_node = None

        for key, val in curr.items():
            value = minmax(val, key, True, tabs + 1)
            if value < best_value:
                if best_node is None:
                    print(f"{indent}MIN {name} started with {key} ({value}).")
                else:
                    print(
                        f"{indent}MIN {name} updated to {value} from {best_value} because of {key} ({value})."
                    )
                best_value = value
                best_node = name
            else:
                print(
                    f"{indent}MIN {name} kept {best_value}, didn't pick {key} ({value})."
                )

        return best_value


print(f"\nFinal Result: {minmax(tree)}")

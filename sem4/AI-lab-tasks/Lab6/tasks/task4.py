def simple_beam_search(tasks, num_processors, beam_width=2):
    # Priority first (high to low), then time (long to short)
    tasks.sort(key=lambda x: (x["priority"], x["time"]), reverse=True)

    beam = [[0] * num_processors]

    for task in tasks:
        all_possibilities = []

        for current_loads in beam:
            for i in range(num_processors):
                next_loads = list(current_loads)  # copy current loads
                next_loads[i] += task["time"]  # add task to processor i
                all_possibilities.append(next_loads)

        # Keep only the top 'beam_width' results for the next task
        all_possibilities.sort(key=lambda x: max(x))
        beam = all_possibilities[:beam_width]

    best_load_distribution = beam[0]
    return best_load_distribution


# Example Data
my_tasks = [
    {"id": "T1", "time": 10, "priority": 3},
    {"id": "T2", "time": 20, "priority": 1},
    {"id": "T3", "time": 15, "priority": 3},
]

final_loads = simple_beam_search(my_tasks, num_processors=2)
print(f"Final loads on processors: {final_loads}")
print(f"The maximum load is: {max(final_loads)}")

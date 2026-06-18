def manhattan_distance(p1, p2):
    return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1])


def greedy_delivery_route(deliveries, start_location, start_time=0):

    current_location = start_location
    current_time = start_time

    route = []
    total_distance = 0

    remaining = deliveries[:]

    while remaining:
        candidates = []

        for delivery in remaining:
            location = delivery["location"]
            window_start = delivery["window"][0]
            window_end = delivery["window"][1]

            travel_time = manhattan_distance(current_location, location)

            arrival_time = current_time + travel_time

            if arrival_time <= window_end:
                # Wait if early
                effective_time = max(arrival_time, window_start)

                urgency = window_end - current_time

                priority = urgency + travel_time

                candidates.append((delivery, priority, travel_time, effective_time))

        if not candidates:
            print("No more deliveries possible within time windows.")
            break

        candidates.sort(key=lambda x: x[1])

        selected, _, travel_time, arrival_time = candidates.pop(0)

        current_time = arrival_time
        current_location = selected["location"]
        total_distance += travel_time

        route.append(selected["name"])
        remaining.remove(selected)

        print(f"Delivered to {selected['name']} at time {current_time}")

    print("\nFinal Route:", route)
    print("Total Distance Traveled:", total_distance)

    return route


deliveries = [
    {"name": "A", "location": (2, 3), "window": (2, 10)},
    {"name": "B", "location": (5, 1), "window": (0, 6)},
    {"name": "C", "location": (6, 4), "window": (5, 15)},
    {"name": "D", "location": (1, 7), "window": (3, 8)},
]

print("Delivery Route Optimization using Greedy Best-First Search\n")

greedy_delivery_route(deliveries, start_location=(0, 0), start_time=0)

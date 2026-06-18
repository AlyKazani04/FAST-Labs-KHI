import numpy as np
import random

# Generate 10 random cities (x, y)
num_cities = 10
cities = np.random.rand(num_cities, 2) * 100


def calculate_distance(order):
    # Calculates total distance of a specific route
    dist = 0
    for i in range(len(order)):
        city_a = cities[order[i]]
        city_b = cities[order[(i + 1) % len(order)]]  # Loop back to start
        dist += np.linalg.norm(city_a - city_b)
    return dist


# GA Components
def initial_population(pop_size, num_cities):
    return [random.sample(range(num_cities), num_cities) for _ in range(pop_size)]


def crossover(parent1, parent2):
    # Ordered Crossover to maintain valid permutations
    size = len(parent1)
    start, end = sorted(random.sample(range(size), 2))

    child = [None] * size
    child[start:end] = parent1[start:end]

    # Fill remaining slots with parent2 genes in order
    p2_remaining = [item for item in parent2 if item not in child]
    for i in range(size):
        if child[i] is None:
            child[i] = p2_remaining.pop(0)
    return child


def mutate(individual, mutation_rate=0.05):
    # Swap mutation: swap two cities in the route.
    if random.random() < mutation_rate:
        idx1, idx2 = random.sample(range(len(individual)), 2)
        individual[idx1], individual[idx2] = individual[idx2], individual[idx1]
    return individual


# The Evolution Loop
def evolve_tsp(pop_size=100, generations=500):
    pop = initial_population(pop_size, num_cities)

    for _ in range(generations):
        # Sort population by fitness (shorter distance = better)
        pop = sorted(pop, key=lambda x: calculate_distance(x))

        # Keep the top 10%
        new_gen = pop[: pop_size // 10]

        # Fill the rest with offspring
        while len(new_gen) < pop_size:
            p1, p2 = random.sample(pop[:50], 2)  # Select from top 50
            child = crossover(p1, p2)
            new_gen.append(mutate(child))

        pop = new_gen

    best_route = pop[0]
    return best_route, calculate_distance(best_route)


best_route, best_dist = evolve_tsp()
print(f"Best Route: {best_route}")
print(f"Distance: {best_dist:.2f}")

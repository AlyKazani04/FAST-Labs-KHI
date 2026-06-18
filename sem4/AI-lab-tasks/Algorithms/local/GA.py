import random

# --- Configuration ---
POP_SIZE = 6  # Number of individuals in population
GENES = 5  # 5-bit binary string (covers 0–31)
GENERATIONS = 20  # How many generations to run
MUTATION_RATE = 0.05  # 5% chance of flipping a bit

# --- Functions ---


def fitness(x):
    return x**2 + x  # f(x) = x² + x (used to evaluate how "good" x is)


def decode(chromosome):
    return int("".join(map(str, chromosome)), 2)  # binary list → integer


def random_chromosome():
    return [random.randint(0, 1) for _ in range(GENES)]  # e.g. [1, 0, 1, 1, 0]


def select(population):
    """Natural selection: pick 2 parents, biased toward higher fitness."""
    weights = [fitness(decode(c)) for c in population]
    # random.choices does weighted (roulette wheel) selection
    return random.choices(population, weights=weights, k=2)


def crossover(parent1, parent2):
    """Single-point crossover: split at a random point and swap tails."""
    point = random.randint(1, GENES - 1)  # e.g. point=3
    child1 = parent1[:point] + parent2[point:]
    child2 = parent2[:point] + parent1[point:]
    return child1, child2


def mutate(chromosome):
    """Single-bit mutation: flip each bit with small probability."""
    return [bit ^ 1 if random.random() < MUTATION_RATE else bit for bit in chromosome]


# --- Main GA Loop ---

# 1. Initialize random population
population = [random_chromosome() for _ in range(POP_SIZE)]

for gen in range(GENERATIONS):
    new_population = []

    # 2. Create next generation
    while len(new_population) < POP_SIZE:
        p1, p2 = select(population)  # Selection
        c1, c2 = crossover(p1, p2)  # Crossover
        new_population.append(mutate(c1))  # Mutation
        new_population.append(mutate(c2))

    population = new_population[:POP_SIZE]

    # Track best this generation
    best = max(population, key=lambda c: fitness(decode(c)))
    best_x = decode(best)
    print(
        f"Gen {gen + 1:2d} | Best chromosome: {best} | x={best_x} | f(x)={fitness(best_x)}"
    )

# --- Final Answer ---
best = max(population, key=lambda c: fitness(decode(c)))
best_x = decode(best)
print(f"\nBest x = {best_x}, f(x) = f({best_x}) = {fitness(best_x)}")
print(f"(The true maximum is x=31, f(31) = {fitness(31)})")

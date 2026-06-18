import random

# Fitness Evaluation (Example: Counting ones in a binary chromosome)
def fitness(chromosome):
    return sum(chromosome)

# Selection (Roulette Wheel Selection)
def roulette_wheel_selection(population, fitness_values):
    total_fitness = sum(fitness_values)
    probabilities = [fitness / total_fitness for fitness in fitness_values]
    selected = random.choices(population, probabilities, k=2)  # Select 2 parents
    return selected

# Crossover (Single-point crossover)
def crossover(parent1, parent2):
    crossover_point = random.randint(1, len(parent1) - 1)
    child1 = parent1[:crossover_point] + parent2[crossover_point:]
    child2 = parent2[:crossover_point] + parent1[crossover_point:]
    return child1, child2

# Mutation (Bit-flip mutation)
def mutate(chromosome, mutation_rate):
    for i in range(len(chromosome)):
        if random.random() < mutation_rate:
            chromosome[i] = 1 - chromosome[i]  # Flip the bit
    return chromosome


def genetic_algorithm(initial_population, generations, mutation_rate):
    population = initial_population
    for generation in range(generations):
        # Fitness evaluation
        fitness_values = [fitness(chromosome) for chromosome in population]

        # Selection
        parents = roulette_wheel_selection(population, fitness_values)

        # Crossover
        Y = [crossover(parents[0], parents[1]) for _ in range(len(population) // 2)]
        offspring = [gene for sublist in Y for gene in sublist]  # ✅ use Y

        # Mutation
        mutated_offspring = [mutate(chromosome, mutation_rate) for chromosome in offspring]

        # Replace old population
        population = mutated_offspring

    # Return the best chromosome
    best_chromosome = max(population, key=fitness)
    return best_chromosome

# Initial population
initial_population = [
    [0, 1, 1, 0, 1],
    [1, 1, 0, 0, 0],
    [0, 1, 0, 0, 0],
    [1, 0, 0, 1, 1]
]

# Genetic Algorithm parameters
generations = 50
mutation_rate = 0.01

# Apply GA
best_solution = genetic_algorithm(initial_population, generations, mutation_rate)
print("Best solution:", best_solution)
print("Fitness:", fitness(best_solution))
import numpy as np

states = ["Sunny", "Cloudy", "Rainy"]
state_map = {0: "Sunny", 1: "Cloudy", 2: "Rainy"}

transition_matrix = np.array([
    [0.7, 0.2, 0.1], # Sunny
    [0.3, 0.4, 0.3], # Cloudy
    [0.2, 0.3, 0.5]  # Rainy
])

def simulate_weather(start_state, days):
    current_state = start_state
    weather_sequence = [state_map[current_state]]
    
    for _ in range(days - 1):
        current_state = np.random.choice([0, 1, 2], p=transition_matrix[current_state])
        weather_sequence.append(state_map[current_state])
        
    return weather_sequence

np.random.seed(32)
ten_day_forecast = simulate_weather(0, 10) # 0 = Sunny
print(f"10-Day Simulation: {ten_day_forecast}")

trials = 10000
at_least_3_rainy = 0

for _ in range(trials):
    sim = simulate_weather(0, 10)
    if sim.count("Rainy") >= 3:
        at_least_3_rainy += 1

probability = at_least_3_rainy / trials
print(f"\nProbability of at least 3 rainy days in 10 days: {probability:.2%}")
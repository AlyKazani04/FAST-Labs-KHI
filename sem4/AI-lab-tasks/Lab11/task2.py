import pandas as pd
import numpy as np
import seaborn as sns
import matplotlib.pyplot as plt
from sklearn.cluster import KMeans
from sklearn.preprocessing import StandardScaler

# 1. Prepare Data
data = {
    'vehicle_serial_no': [5, 3, 8, 2, 4, 7, 6, 10, 1, 9],
    "mileage": [150000, 120000, 250000, 80000, 100000, 220000, 180000, 300000, 75000, 280000],
    "fuel_efficiency": [15, 18, 10, 22, 20, 12, 16, 8, 24, 9],
    "maintenance_cost": [5000, 4000, 7000, 2000, 3000, 6500, 5500, 8000, 1500, 7500],
    "vehicle_type": ["SUV", "Sedan", "Truck", "Hatchback", "Sedan", "Truck", "SUV", "Truck", "Hatchback", "SUV"]
}

df = pd.DataFrame(data)

# Encode Categorical Feature (vehicle_type)
df_encoded = pd.get_dummies(df, columns=['vehicle_type'])

# Drop serial number for clustering as it's an identifier, not a feature
X = df_encoded.drop('vehicle_serial_no', axis=1)

# 2. K-Means WITHOUT Scaling
kmeans_no_scaling = KMeans(n_clusters=3, random_state=42, n_init=10)
df['cluster_no_scaling'] = kmeans_no_scaling.fit_predict(X)

# 3. K-Means WITH Scaling
# We scale all columns (including encoded categorical ones as they are now numeric)
scaler = StandardScaler()
X_scaled = scaler.fit_transform(X)

kmeans_scaled = KMeans(n_clusters=3, random_state=42, n_init=10)
df['cluster_with_scaling'] = kmeans_scaled.fit_predict(X_scaled)

print(df[['vehicle_serial_no', 'mileage', 'fuel_efficiency', 'cluster_no_scaling', 'cluster_with_scaling']])

# 4. Visualization Comparison
fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(16, 6))

# Plot 1: Unscaled
sns.scatterplot(data=df, x='mileage', y='fuel_efficiency', hue='cluster_no_scaling', 
                palette='viridis', s=100, ax=ax1)
ax1.set_title('K-Means: NO SCALING\n(Mileage dominates the logic)', fontsize=14)

# Plot 2: Scaled
sns.scatterplot(data=df, x='mileage', y='fuel_efficiency', hue='cluster_with_scaling', 
                palette='viridis', s=100, ax=ax2)
ax2.set_title('K-Means: WITH SCALING\n(Balanced influence of all features)', fontsize=14)

plt.tight_layout()
plt.show()
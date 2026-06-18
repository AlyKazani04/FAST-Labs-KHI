import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.cluster import KMeans
from sklearn.preprocessing import StandardScaler

# 1. Generate Synthetic Student Data
np.random.seed(42)
n_students = 50
data = {
    'student_id': range(101, 101 + n_students),
    'GPA': np.round(np.concatenate([
        np.random.normal(3.5, 0.3, 15), # High performers
        np.random.normal(2.5, 0.4, 20), # Average
        np.random.normal(1.8, 0.4, 15)  # Struggling
    ]), 2),
    'study_hours': np.round(np.concatenate([
        np.random.normal(25, 5, 15),
        np.random.normal(15, 4, 20),
        np.random.normal(8, 3, 15)
    ]), 1),
    'attendance_rate': np.round(np.concatenate([
        np.random.normal(90, 5, 15),
        np.random.normal(75, 10, 20),
        np.random.normal(60, 15, 15)
    ]), 1)
}

# Clip values to realistic bounds
df = pd.DataFrame(data)
df['GPA'] = df['GPA'].clip(0.0, 4.0)
df['study_hours'] = df['study_hours'].clip(0, 60)
df['attendance_rate'] = df['attendance_rate'].clip(0, 100)

# 2. Feature Selection
features = ['GPA', 'study_hours', 'attendance_rate']
X = df[features]

# 3. Feature Scaling
scaler = StandardScaler()
X_scaled = scaler.fit_transform(X)

# 4. Elbow Method (K=2 to 6)
inertia = []
K_range = range(2, 7)
for k in K_range:
    km = KMeans(n_clusters=k, random_state=42, n_init=10)
    km.fit(X_scaled)
    inertia.append(km.inertia_)

# Plot Elbow Method
plt.figure(figsize=(8, 5))
plt.plot(K_range, inertia, 'bo-')
plt.xlabel('Number of Clusters (K)')
plt.ylabel('Inertia (Within-cluster Sum of Squares)')
plt.title('Elbow Method for Optimal K')
plt.grid(True)
plt.show()

# 5. Perform Clustering with Optimal K (Visual elbow is at 3)
optimal_k = 3
kmeans = KMeans(n_clusters=optimal_k, random_state=42, n_init=10)
df['cluster'] = kmeans.fit_predict(X_scaled)

# 6. Visualization: GPA vs Study Hours
plt.figure(figsize=(10, 6))
sns.scatterplot(data=df, x='study_hours', y='GPA', hue='cluster', palette='Set1', s=100, alpha=0.8)
plt.title(f'Student Segments (K={optimal_k}): GPA vs Weekly Study Hours', fontsize=14)
plt.xlabel('Average Weekly Study Hours')
plt.ylabel('GPA')
plt.legend(title='Cluster')
plt.grid(True, linestyle='--', alpha=0.6)
plt.show()

# Display Deliverables (first 15 rows)
print(df[['student_id', 'GPA', 'study_hours', 'attendance_rate', 'cluster']].head(15))
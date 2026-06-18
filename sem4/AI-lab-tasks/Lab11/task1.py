# Import libraries
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.cluster import KMeans
from sklearn.preprocessing import StandardScaler, LabelEncoder

# Load dataset
# df = pd.read_csv('Mall_Customers.csv')
# No dataset provided, creating...
np.random.seed(42)
n = 100

# Customer IDs
customer_id = range(1, n+1)

# Gender: 0 = Female, 1 = Male (roughly balanced)
gender = np.random.choice([0, 1], size=n, p=[0.55, 0.45])

# Age: between 18 and 70
age = np.random.randint(18, 71, size=n)

# Annual Income (k$): right‑skewed, typical range 15–140
annual_income = np.random.gamma(shape=2, scale=20, size=n).astype(int) + 15
annual_income = np.clip(annual_income, 15, 140)

# Spending Score (1–100): correlated moderately with age and income
spending_score = (50 
                  - 0.3 * (age - 40) 
                  + 0.4 * (annual_income - 50) / 30 * 50 
                  + np.random.normal(0, 15, n))
spending_score = np.clip(spending_score, 1, 100).astype(int)

# Create DataFrame
df = pd.DataFrame({
    'CustomerID': customer_id,
    'Gender': gender,
    'Age': age,
    'Annual Income (k$)': annual_income,
    'Spending Score (1-100)': spending_score
})

# Convert Gender back to string for realism (optional)
df['Gender'] = df['Gender'].map({0: 'Female', 1: 'Male'})

df.head(10)
df.to_csv('Mall_Customers.csv', index=False)
print("Synthetic dataset saved as 'Mall_Customers.csv'")

print("Original data shape:", df.shape)
df.head()

# Encode categorical column 'gender' -> 0 (Female), 1 (Male)
le = LabelEncoder()
df['Gender'] = le.fit_transform(df['Gender'])

# Select features: all except CustomerID
features = ['Gender', 'Age', 'Annual Income (k$)', 'Spending Score (1-100)']
X = df[features].values

# ------------------------------------------------------------
# 1. Clustering WITHOUT any scaling
# ------------------------------------------------------------
# Determine optimal k using elbow method (for illustration)
wcss_no_scale = []
for i in range(1, 11):
    kmeans = KMeans(n_clusters=i, init='k-means++', random_state=42, n_init=10)
    kmeans.fit(X)
    wcss_no_scale.append(kmeans.inertia_)

plt.figure(figsize=(12,4))
plt.subplot(1,2,1)
plt.plot(range(1,11), wcss_no_scale, marker='o')
plt.title('Elbow Method - No Scaling')
plt.xlabel('Number of clusters')
plt.ylabel('WCSS')

# Use k=4 (elbow point) for final clustering
k_opt = 4
kmeans_no_scale = KMeans(n_clusters=k_opt, init='k-means++', random_state=42, n_init=10)
y_no_scale = kmeans_no_scale.fit_predict(X)

# ------------------------------------------------------------
# 2. Clustering WITH scaling applied to all features except Age
# ------------------------------------------------------------
# Separate Age from other features
age_col = X[:, 1].reshape(-1,1)          # Age remains unscaled
other_cols = X[:, [0,2,3]]               # Gender, Annual Income, Spending Score

scaler = StandardScaler()
other_scaled = scaler.fit_transform(other_cols)

# Combine: scaled other features + original Age
X_scaled_except_age = np.hstack([other_scaled, age_col])

# Elbow method for scaled data
wcss_scaled = []
for i in range(1, 11):
    kmeans = KMeans(n_clusters=i, init='k-means++', random_state=42, n_init=10)
    kmeans.fit(X_scaled_except_age)
    wcss_scaled.append(kmeans.inertia_)

plt.subplot(1,2,2)
plt.plot(range(1,11), wcss_scaled, marker='o', color='green')
plt.title('Elbow Method - Scaling except Age')
plt.xlabel('Number of clusters')
plt.ylabel('WCSS')
plt.tight_layout()
plt.show()

# Use same k=4 for fair comparison
kmeans_scaled = KMeans(n_clusters=k_opt, init='k-means++', random_state=42, n_init=10)
y_scaled = kmeans_scaled.fit_predict(X_scaled_except_age)

# ------------------------------------------------------------
# Analyse & compare results
# ------------------------------------------------------------
def cluster_summary(X, labels, feature_names, title):
    df_res = pd.DataFrame(X, columns=feature_names)
    df_res['Cluster'] = labels
    summary = df_res.groupby('Cluster').mean().round(2)
    sizes = df_res['Cluster'].value_counts().sort_index()
    print(f"\n{title}\nCluster sizes:\n{sizes}\n")
    print("Centroids (mean values):\n", summary)
    return summary, sizes

feature_names = features

print("="*60)
sum_no_scale, sizes_no_scale = cluster_summary(X, y_no_scale, feature_names, "NO SCALING")
print("="*60)
other_cols_inv = scaler.inverse_transform(other_scaled)
X_orig_scale = np.hstack([other_cols_inv, age_col])
sum_scaled, sizes_scaled = cluster_summary(X_orig_scale, y_scaled, feature_names, "SCALING (except Age)")
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.svm import SVC
from sklearn.tree import DecisionTreeClassifier, plot_tree
from sklearn.metrics import classification_report, confusion_matrix

# 1. Dataset Creation & Cleaning
data = {
    'spending_6m': [1000, 150, 1200, 300, 50, 2000, 400, 1100, 90, 1500],
    'age': [25, 34, 45, 23, 19, 50, 31, 40, 22, 35],
    'visits': [15, 2, 20, 5, 1, 25, 6, 18, 2, 22],
    'is_high_value': [1, 0, 1, 0, 0, 1, 0, 1, 0, 1]
}
df = pd.DataFrame(data)

# Handle Missing/Outliers: Using median for robustness
df.fillna(df.median(), inplace=True)

# 2. Feature Scaling (Syllabus Requirement: Scaling)
# Crucial for SVM (Hyperplane) as it is distance-based
X = df.drop('is_high_value', axis=1)
y = df['is_high_value']

scaler = StandardScaler()
X_scaled = scaler.fit_transform(X)

# 3. Train/Test Split
X_train, X_test, y_train, y_test = train_test_split(X_scaled, y, test_size=0.2, random_state=42)

# 4. Find the Separating Hyperplane (SVM)
# Linear kernel finds the actual linear hyperplane
svm_model = SVC(kernel='linear')
svm_model.fit(X_train, y_train)

# 5. Find Classification Rules (Decision Tree)
# Trees are used specifically for generating "If-Then" rules
dt_model = DecisionTreeClassifier(criterion='entropy', max_depth=3)
dt_model.fit(X_train, y_train) # Using scaled data for consistency

# 6. Evaluation
y_pred = svm_model.predict(X_test)
print("--- SVM (Hyperplane) Evaluation ---")
print(classification_report(y_test, y_pred))

# Visualizing the Rules (The Tree)
plt.figure(figsize=(10,6))
plot_tree(dt_model, feature_names=X.columns, class_names=['Low-Value', 'High-Value'], filled=True)
plt.title("Customer Classification Rules")
plt.show()
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler, LabelEncoder
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error, r2_score, mean_absolute_error
import warnings
warnings.filterwarnings('ignore')

data = {
    'sq_ft': [1500, 2000, 1200, 2500, np.nan, 1800, 3000, 1100, 2100, 1600],
    'bedrooms': [3, 4, 2, 4, 3, 3, 5, 2, 4, 3],
    'bathrooms': [2, 2.5, 1, 3, 2, 2, 3.5, 1, 2.5, 2],
    'age': [10, 5, 20, 1, 15, 8, 2, 30, 6, 12],
    'neighborhood': ['Suburbs', 'Downtown', 'Suburbs', 'Downtown', 'Rural', 'Rural', 'Downtown', 'Suburbs', 'Rural', 'Suburbs'],
    'price': [300000, 450000, 210000, 550000, 280000, 310000, 680000, 190000, 400000, 320000]
}

df = pd.DataFrame(data)

df['sq_ft'] = df['sq_ft'].fillna(df['sq_ft'].mean())

le = LabelEncoder()
df['neighborhood'] = le.fit_transform(df['neighborhood']) # Encoding

print("DataSet:", df.describe())
plt.figure(figsize=(8,6))
sns.heatmap(df.corr(), annot=True, cmap='coolwarm') # Plotting and interpretation
plt.title("Feature Correlation Heatmap")
plt.show()

X = df[['sq_ft', 'bedrooms', 'bathrooms', 'age', 'neighborhood']]
y = df['price']

scaler = StandardScaler()
X_scaled = scaler.fit_transform(X)

X_train, X_test, y_train, y_test = train_test_split(X_scaled, y, test_size=0.2)
model = LinearRegression()
model.fit(X_train, y_train)

preds = model.predict(X_test)
print(f"R2 Score: {r2_score(y_test, preds)}")
print(f"MSE: {mean_squared_error(y_test, preds)}")
print(f"MAE: {mean_absolute_error(y_test, preds)}")

new_house = [[2200, 3, 2, 5, 0]]
new_house_scaled = scaler.transform(new_house)
prediction = model.predict(new_house_scaled)
print(f"\nPredicted Price for new house: ${prediction[0]:,.2f}")
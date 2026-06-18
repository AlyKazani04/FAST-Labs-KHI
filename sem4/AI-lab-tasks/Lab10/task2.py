import pandas as pd
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.linear_model import LogisticRegression
from sklearn.tree import DecisionTreeClassifier, plot_tree
from sklearn.metrics import confusion_matrix, classification_report
from sklearn.model_selection import train_test_split
import matplotlib.pyplot as plt
import seaborn as sns

data = {
    'content': [
        "Congratulations! You've won a $1,000 Walmart gift card. Click here.",
        "Hey, are we still meeting for lunch at 12:30 today?",
        "Urgent: Your account has been compromised. Verify your password now.",
        "The draft for the quarterly report is attached for your review.",
        "Get cheap meds online without a prescription! Limited offer.",
        "Don't forget to pick up milk on your way home tonight.",
        "Claim your prize now!",
        "Meeting notes from yesterday."
    ],
    'is_spam': [1, 0, 1, 0, 1, 0, 1, 0]
}

df = pd.DataFrame(data)

# Preprocessing
vectorizer = TfidfVectorizer(stop_words='english')
X = vectorizer.fit_transform(df['content'])
y = df['is_spam']

# Modeling
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=.25, random_state=1)
dt_model = DecisionTreeClassifier(criterion='entropy', max_depth=3) # Information Gain
dt_model.fit(X_train, y_train)

# Evaluation
y_pred = dt_model.predict(X_test)
cm = confusion_matrix(y_test, y_pred)
plt.figure(figsize=(6,4))
sns.heatmap(cm, annot=True, fmt='d', cmap='Blues', xticklabels=['Not Spam', 'Spam'], yticklabels=['Not Spam', 'Spam'])
plt.xlabel('Predicted')
plt.ylabel('Actual')
plt.title('Confusion Matrix')
plt.show()

plt.figure(figsize=(12, 8))
plot_tree(dt_model, feature_names=vectorizer.get_feature_names_out(), class_names=['Ham', 'Spam'], filled=True)
plt.title("Decision Tree Logic (Information Gain)")
plt.show()

print(classification_report(y_test, y_pred))
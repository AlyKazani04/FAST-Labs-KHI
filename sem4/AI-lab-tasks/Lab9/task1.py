from pgmpy.models import DiscreteBayesianNetwork
from pgmpy.factors.discrete import TabularCPD
from pgmpy.inference import VariableElimination

model = DiscreteBayesianNetwork([("Suit", "Color"), ("Value", "IsFaceCard")])
suit_names = ["Hearts", "Diamonds", "Clubs", "Spades"]
cpd_suit = TabularCPD(
    variable="Suit", 
    variable_card=4, 
    values=[[0.25], [0.25], [0.25], [0.25]], 
    state_names={"Suit": suit_names}
)

cpd_value = TabularCPD(
    variable="Value", 
    variable_card=13, 
    values=[[1 / 13]] * 13,
    state_names={"Value": list(range(1,14))}
)

color_names = ["Red", "Black"]
cpd_color = TabularCPD(
    variable="Color",
    variable_card=2,
    values=[
        [1,1,0,0], 
        [0,0,1,1],
    ],
    evidence=["Suit"],
    evidence_card=[4],
    state_names={"Suit": suit_names, "Color": color_names},
)

face_probs = [0] * 10 + [1] * 3
not_face_probs = [1] * 10 + [0] * 3
cpd_face = TabularCPD(
    variable="IsFaceCard",
    variable_card=2,
    values=[
        not_face_probs,
        face_probs,
    ],
    evidence=["Value"],
    evidence_card=[13],
    state_names={"Value": list(range(1, 14)), "IsFaceCard": ["No", "Yes"]},
)

model.add_cpds(cpd_suit, cpd_value, cpd_color, cpd_face)

assert model.check_model()

infer = VariableElimination(model)

print("1. P(Red) = ?")
res1 = infer.query(variables=['Color'])
print(f"  > {res1.values[0]}") 

print("2. P(Heart | Red)= ?")
res2 = infer.query(variables=['Suit'], evidence={'Color': 'Red'})
print(f"  > {res2.values[0]}")

print("3. P(FaceCard | Diamond) = ?")
res3 = infer.query(variables=['IsFaceCard'], evidence={'Suit': 'Diamonds'})
print(f'  > {res3.values[1]}')

print("4. P(Spade or Queen | FaceCard) = ?")
res4 = infer.query(variables=['Suit', 'Value'], evidence={'IsFaceCard' : 'Yes'})
spade_prob = res4.values[3].sum()
queen_prob = res4.values[:, 11].sum()
print(f"  > {spade_prob + queen_prob}")
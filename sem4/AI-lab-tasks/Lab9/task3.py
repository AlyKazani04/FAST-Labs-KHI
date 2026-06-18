from pgmpy.models import DiscreteBayesianNetwork
from pgmpy.factors.discrete import TabularCPD
from pgmpy.inference import VariableElimination

model = DiscreteBayesianNetwork([
    ('Disease', 'Fever'),
    ('Disease', 'Cough'),
    ('Disease', 'Fatigue'),
    ('Disease', 'Chills')
])

cpd_disease = TabularCPD(
    variable='Disease', variable_card=2, 
    values=[[0.3], [0.7]],
    state_names={'Disease': ['Flu', 'Cold']}
)

cpd_fever = TabularCPD(
    variable='Fever', variable_card=2,
    values=[[0.9, 0.5],  # Yes
            [0.1, 0.5]], # No
    evidence=['Disease'], evidence_card=[2],
    state_names={'Fever': ['Yes', 'No'], 'Disease': ['Flu', 'Cold']}
)

cpd_cough = TabularCPD(
    variable='Cough', variable_card=2,
    values=[[0.8, 0.6],  # Yes
            [0.2, 0.4]], # No
    evidence=['Disease'], evidence_card=[2],
    state_names={'Cough': ['Yes', 'No'], 'Disease': ['Flu', 'Cold']}
)

cpd_fatigue = TabularCPD(
    variable='Fatigue', variable_card=2,
    values=[[0.7, 0.3],  # Yes
            [0.3, 0.7]], # No
    evidence=['Disease'], evidence_card=[2],
    state_names={'Fatigue': ['Yes', 'No'], 'Disease': ['Flu', 'Cold']}
)

cpd_chills = TabularCPD(
    variable='Chills', variable_card=2,
    values=[[0.6, 0.4],  # Yes
            [0.4, 0.6]], # No
    evidence=['Disease'], evidence_card=[2],
    state_names={'Chills': ['Yes', 'No'], 'Disease': ['Flu', 'Cold']}
)

model.add_cpds(cpd_disease, cpd_fever, cpd_cough, cpd_fatigue, cpd_chills)
assert model.check_model()
infer = VariableElimination(model)

print("P(Disease | Fever=Yes, Cough=Yes) : ")
print(infer.query(variables=['Disease'], evidence={'Fever': 'Yes', 'Cough': 'Yes'}))

print("\nP(Disease | Fever=Yes, Cough=Yes, Chills=Yes) : ")
print(infer.query(variables=['Disease'], evidence={'Fever': 'Yes', 'Cough': 'Yes', 'Chills': 'Yes'}))

print("\nP(Fatigue=Yes | Disease=Flu) : ")
print(infer.query(variables=['Fatigue'], evidence={'Disease': 'Flu'}))
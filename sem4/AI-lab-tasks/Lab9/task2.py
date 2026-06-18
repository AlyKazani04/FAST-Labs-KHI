from pgmpy.models import DiscreteBayesianNetwork
from pgmpy.factors.discrete import TabularCPD
from pgmpy.inference import VariableElimination

model = DiscreteBayesianNetwork([
    ('Intelligence', 'Grade'),
    ('StudyHours', 'Grade'),
    ('Difficulty', 'Grade'),
    ('Grade', 'Pass')
])

cpd_i = TabularCPD('Intelligence', 2, [[0.7], [0.3]], state_names={'Intelligence': ['High', 'Low']})

cpd_s = TabularCPD('StudyHours', 2, [[0.6], [0.4]], state_names={'StudyHours': ['Sufficient', 'Insufficient']})

cpd_d = TabularCPD('Difficulty', 2, [[0.4], [0.6]], state_names={'Difficulty': ['Hard', 'Easy']})

cpd_g = TabularCPD(
    'Grade', 3, 
    [
        # Intelligence: High | Low
        # StudyHours:   Suff | Insuff | Suff | Insuff
        # Difficulty:   H  E | H  E   | H  E | H  E
        [0.6, 0.9, 0.4, 0.7, 0.2, 0.5, 0.1, 0.3], # Grade A
        [0.3, 0.08, 0.4, 0.2, 0.4, 0.3, 0.3, 0.4], # Grade B
        [0.1, 0.02, 0.2, 0.1, 0.4, 0.2, 0.6, 0.3]  # Grade C
    ],
    evidence=['Intelligence', 'StudyHours', 'Difficulty'],
    evidence_card=[2, 2, 2],
    state_names={
        'Grade': ['A', 'B', 'C'],
        'Intelligence': ['High', 'Low'],
        'StudyHours': ['Sufficient', 'Insufficient'],
        'Difficulty': ['Hard', 'Easy']
    }
)

cpd_p = TabularCPD(
    'Pass', 2,
    [
        [0.95, 0.80, 0.50], # Pass: Yes
        [0.05, 0.20, 0.50]  # Pass: No
    ],
    evidence=['Grade'],
    evidence_card=[3],
    state_names={'Pass': ['Yes', 'No'], 'Grade': ['A', 'B', 'C']}
)

model.add_cpds(cpd_i, cpd_s, cpd_d, cpd_g, cpd_p)
assert model.check_model()

infer = VariableElimination(model)

print("P(Passes | Sufficient study, Hard difficulty) :")
result_a = infer.query(variables=['Pass'], evidence={'StudyHours': 'Sufficient', 'Difficulty': 'Hard'})
print(result_a)

print("\nP(High Intelligence | student passed) :")
result_b = infer.query(variables=['Intelligence'], evidence={'Pass': 'Yes'})
print(result_b)
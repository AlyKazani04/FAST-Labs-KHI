class ResponseAgent:
    def execute_response(self):
        print("Executing Response: Base!")

class AlertAgent(ResponseAgent):
    def execute_response(self):
        print("Executing Response: Sending Notifications!")

class BlockAgent(ResponseAgent):
    def execute_response(self):
        print("Executing Response: Blocking Malicious Activities!")
    
class RecoverAgent(ResponseAgent):
    def execute_response(self):
        print("Executing Response: Restoring Affected Systems!")

agent_list = [ResponseAgent(), AlertAgent(), BlockAgent(), RecoverAgent()]

for a in agent_list:
    a.execute_response()
import random

class ServerEnvironment:
    def __init__(self):
        self.__servers = {
            "1" : random.choice([{"Underloaded" : 2}, {"Balanced" : 5}, {"Overloaded" : 8}]),
            "2" : random.choice([{"Underloaded" : 2}, {"Balanced" : 5}, {"Overloaded" : 8}]),
            "3" : random.choice([{"Underloaded" : 2}, {"Balanced" : 5}, {"Overloaded" : 8}]),
            "4" : random.choice([{"Underloaded" : 2}, {"Balanced" : 5}, {"Overloaded" : 8}]),
            "5" : random.choice([{"Underloaded" : 2}, {"Balanced" : 5}, {"Overloaded" : 8}])
        }
        print("Iniitial Server Environment:")
        self.display_servers()
    
    def display_servers(self):
        for server_id, status in self.__servers.items():
            print(f"Server {server_id}: {list(status.keys())[0]} with {list(status.values())[0]} tasks")

    def get_servers(self):
        return self.__servers

class LoadBalancerAgent:

    def analyze_servers(self, servers: dict):
        underloaded = []
        balanced = []
        overloaded = []

        print("\nAnalyzing Server Loads:")
        for server_id, status_dict in servers.items():
            status, load = list(status_dict.items())[0]
            if status == "Underloaded":
                underloaded.append((server_id, load))
            elif status == "Balanced":
                balanced.append((server_id, load))
            elif status == "Overloaded":
                overloaded.append((server_id, load))
            print(f"Server {server_id} is {status} with {load} tasks.")

        return underloaded, balanced, overloaded

    def redistribute_load(self, servers: dict):
        servers = env.get_servers()
        underloaded, balanced, overloaded = self.analyze_servers(servers)

        print("\nRedistributing Loads for Optimal Performance:")
        for o_server_id, o_load in overloaded:
            while o_load > 5 and underloaded:
                u_server_id, u_load = underloaded[0]
                transfer_load = min(o_load - 5, 5 - u_load)
                
                o_load -= transfer_load
                u_load += transfer_load
                
                servers[o_server_id] = {"Overloaded" if o_load > 5 else "Balanced" if o_load == 5 else "Underloaded": o_load}
                servers[u_server_id] = {"Underloaded" if u_load < 5 else "Balanced" if u_load == 5 else "Overloaded": u_load}
                
                print(f"Transferred {transfer_load} tasks from Server {o_server_id} to Server {u_server_id}.")
                
                if u_load == 5:
                    underloaded.pop(0)
                else:
                    underloaded[0] = (u_server_id, u_load)


lba = LoadBalancerAgent()
env = ServerEnvironment()

lba.analyze_servers(env.get_servers())

lba.redistribute_load(env.get_servers())

print("\nPost-redistribution Server Environment:")
env.display_servers()

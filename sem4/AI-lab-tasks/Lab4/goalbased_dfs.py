class GoalBasedAgent:
    def __init__(self, goal):
        self.goal = goal
    
    def formulate_goal(self, percept):
        if percept == self.goal:
            return "Goal Reached"
        return "Searching"
    
    def dfs(self, tree, start, goal, depth_limit):
        level = 0
        stack = []
        visited = []
        stack.append(start)
        visited.append(start)

        while stack:
            node = stack.pop()
            print(f"Visiting: {node}")

            if goal == node:
                return f"Goal Reached! Depth: {level}"

            if level == depth_limit:
                return f"Depth Reached: {level}"

            for neighbor in reversed(tree[node]):
                if neighbor not in visited:
                    visited.append(neighbor)
                    stack.append(neighbor)

            level += 1
        return "Goal Not Found"
    
    def act(self, percept, tree, limit):
        goal_status = self.formulate_goal(percept)
        if goal_status == "Goal Reached":
            return "Goal Found!"
        return self.dfs(tree, percept, self.goal, limit)
    
class Environment:
    def __init__(self, tree):
        self.tree = tree
    def get_percept(self, node):
        return node
    
def run_agent(agent, env, start_node, depth_limit):
    percept = env.get_percept(start_node)
    action = agent.act(percept, env.tree, depth_limit)
    print(action)

tree = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F', 'G'],
    'D': ['H'],
    'E': [],
    'F': ['I'],
    'G': [],
    'H': [],
    'I': []
}

start_node = "A"
goal_node = "E"
limit = 1

agent = GoalBasedAgent(goal=goal_node)
env = Environment(tree=tree)

run_agent(agent=agent, env=env, start_node=start_node, depth_limit=limit)
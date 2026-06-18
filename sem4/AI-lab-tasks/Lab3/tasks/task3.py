import random

class ServerEnvironment:
    def __init__(self):
        self.__backup_tasks = [
            {"1" : random.choice(["Completed", "Failed"])},
            {"2" : random.choice(["Completed", "Failed"])},
            {"3" : random.choice(["Completed", "Failed"])},
            {"4" : random.choice(["Completed", "Failed"])},
            {"5" : random.choice(["Completed", "Failed"])}
        ]
        print("Initial Backup Tasks Status:")
        self.display_backup_tasks()

    def display_backup_tasks(self):
        for task in self.__backup_tasks:
            tasknum = list(task.keys())[0]
            taskstatus = task[list(task.keys())[0]]

            print(f"Task #{tasknum} Status: {taskstatus}")

    def get_backup_tasks(self):
        return self.__backup_tasks
    
class BackupManagementAgent:
    def scan_for_fails(self, env: ServerEnvironment):
        print("\nScanning Backup Tasks...")
        tasks = env.get_backup_tasks()
        failed_tasks = [status for status in tasks for task, res in status.items() if res == "Failed"]
        for task in failed_tasks:
            tasknum = list(task.keys())[0]

            print(f"Failed Task Detected! ID: {tasknum}")
        return failed_tasks

    def retry_backup_tasks(self, tasks:list[dict[str,str]]):
        print("\nRetrying failed backup tasks...")
        for task in tasks:
            while task[list(task.keys())[0]] == "Failed":
                print(f"\nRetrying backup task {task}...")
                task[list(task.keys())[0]] = random.choice(["Completed", "Failed"])
                print(f"Task status after retry: {task[list(task.keys())[0]]}")
        print("\nAll retry attempts completed.")

bma = BackupManagementAgent()
env = ServerEnvironment()

failed_tasks = bma.scan_for_fails(env)
bma.retry_backup_tasks(failed_tasks)
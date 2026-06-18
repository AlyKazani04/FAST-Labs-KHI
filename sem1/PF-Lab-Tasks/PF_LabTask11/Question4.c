#include <stdio.h>
typedef struct{
	char name[50];
	int dateofbirth[3];
	int employeeID;
	char department[50];
	int salary;
} Employee;
int addemployee(Employee employee[], int *num, int addcount){
	int i;
	for( i = *num; i < *num + addcount ; i++){
		printf("Enter Employee %d Name : ", i+1);
		scanf(" %49[^\n]%*c", employee[i].name);
		printf("Enter Employee %d Day of Birth(DD): ", i+1);
		scanf("%d", &employee[i].dateofbirth[0]);
		printf("Enter Employee %d Month of Birth(MM): ", i+1);
		scanf("%d", &employee[i].dateofbirth[1]);
		printf("Enter Employee %d Year of Birth(YYYY): ", i+1);
		scanf("%d", &employee[i].dateofbirth[2]);
		printf("Enter Employee %d ID : ", i+1);
		scanf("%d", &employee[i].employeeID);
		printf("Enter Employee %d Department : ", i+1);
		scanf(" %49[^\n]%*c", employee[i].department);
		printf("Enter Employee %d Salary : ", i+1);
		scanf("%d", &employee[i].salary);
	}
	*num += addcount;
	printf("_________________________\n\n");
	return 0;
}
int deleteemployee(Employee employee[], int *num, int ID){
	int i, j;
	for( i = 0; i < *num ; i++){
		if (employee[i].employeeID == ID){
			for(j = i ; j < *num ; j++){
				employee[j] = employee[j+1];
			}
			(*num)--;
			printf("Deleted\n");
			printf("_________________________\n\n");
			return 0;
		}
	}
	printf("Employee ID not Found\n");
	printf("_________________________\n\n");
	return 0;
}
int displayemployees(Employee employee[], int *num){
	int i;
	if(num == 0){
		printf("No Employees Available\n");
		printf("_________________________\n\n");
		return 0;
	}
	for(i = 0; i < num; i++){
		printf("Employee %d Name: %s\n", i + 1, employee[i].name);
		printf("Date of Birth : %02d-%02d-%04d\n", employee[i].dateofbirth[0], employee[i].dateofbirth[1], employee[i].dateofbirth[2]);
		printf("Employee ID : %d\n", employee[i].employeeID);
		printf("Department: %s\n", employee[i].department);
		printf("Salary: %d\n", employee[i].salary);
		printf("\n");
	}
	printf("_________________________\n\n");
	return 1;
}
int main(){
	int num = 0, n, addcount, idin;
	Employee employee[50];
	while(1){
		printf("Enter 1 to Add an Employee, 2 to Delete an Employee, 3 to Display All Available Employees, 0 to exit : ");
		if(scanf("%d", &n) != 1){
        	printf("Invalid input. Please enter a number.\n");
        	while (getchar() != '\n');
        	printf("_________________________\n\n");
        	continue;
    	}
    	printf("_________________________\n\n");
    	switch(n){
    		case 1:
    			printf("Enter the Number of Employees you would like to Add : ");
    			scanf("%d", &addcount);
    			if(num + addcount > 50){
    				printf("Cannot add more employees. Limit reached.\n");
    				printf("_________________________\n\n");
				}
				else{
	    			addemployee(employee, &num, addcount);
				}
    			break;
    		case 2:
    			printf("Enter the ID of the Employee you would like to Remove : ");
    			scanf("%d", &idin);
    			deleteemployee(employee, &num, idin);
    			break;
    		case 3:
    			displayemployees(employee, num);
    			break;
    		case 0:
    			printf("Operation Ended");
    			return 0;
    		default:
    			printf("Invalid Input Try Again.");
    			break;
		}
	}
	return 0;
}

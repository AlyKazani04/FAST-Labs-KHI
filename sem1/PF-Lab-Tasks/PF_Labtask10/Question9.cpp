#include <stdio.h>
typedef struct employees{
		int id;
		char name[50];
		char department[50];
		int salary;
};
void addEmployees(employees emp[], int *num, int addcount){
	for(int i = *num; i < *num + addcount ; i++){
		printf("Enter Employee %d ID : ", i+1);
		scanf("%d", &emp[i].id);
		printf("Enter Employee %d Name : ", i+1);
		scanf("%s", emp[i].name);
		printf("Enter Employee %d Department : ", i+1);
		scanf("%s", emp[i].department);
		printf("Enter Employee %d Salary : ", i+1);
		scanf("%d", &emp[i].salary);
	}
	*num += addcount;
	printf("_________________________\n\n");
}
void displayEmployees(employees emp[], int num){
	if(num==0){
		printf("No Employees Available\n");
		printf("_________________________\n\n");
		return;
	}
	for(int i= 0; i<num; i++){
		printf("Employee %d ID = %d\n", i+1, emp[i].id);
		printf("Employee %d Name = %s\n", i+1, emp[i].name);
		printf("Employee %d Department = %s\n", i+1, emp[i].department);
		printf("Employee %d Salary = %d\n", i+1, emp[i].salary);
		printf("\n");
	}
	printf("_________________________\n\n");
	return;
}

int main(){
	employees emp[100];
	int num=0, n, addcount;
	char arr[100];
	while(1){
		printf("Enter 1 to Add Employees, 2 to Display Employees or 0 to End : ");
		scanf("%d", &n);
		switch(n){
			case 1:
				printf("Enter the number of Employees you would like to add : ");
				scanf("%d", &addcount);
				addEmployees(emp, &num, addcount);
				break;
			case 2:
				printf("Employees available :\n");
				displayEmployees(emp, num);
				break;
			case 0:
				printf("Operation Ended.\n");
				return 0;
			default:
				printf("Invalid Entry Try Again\n");
		}
	}
	return 0;
}

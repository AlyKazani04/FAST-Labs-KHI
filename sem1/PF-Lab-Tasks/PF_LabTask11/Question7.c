#include <stdio.h>
#include <string.h>
#define MAXCOURSES 5
#define MAXDEPTS 5
#define MAXSTRING 100
typedef struct {
	int courseID;
	char coursename[MAXSTRING];
	char instructor[MAXSTRING];
	int credits;
} Course;
typedef struct {
	char deptname[MAXSTRING];
	Course courses[MAXCOURSES];
	int coursecount; 
} Department;
void adddept(Department departments[], int *deptcount){
	if(*deptcount >= MAXDEPTS){
		printf("Maximum number of departments reached.\n");
		return;
	}
	printf("Enter department name: ");
	getchar();
	fgets(departments[*deptcount].deptname, MAXSTRING, stdin);
	departments[*deptcount].deptname[strcspn(departments[*deptcount].deptname, "\n")] = 0; 
	departments[*deptcount].coursecount = 0;
	(*deptcount)++;
	printf("Department added.\n");
}
void addcourse(Department departments[], int deptcount){
	int i;
	if(deptcount == 0){
		printf("No departments available. Please add a department first.\n");
		return;
	}
	char deptname[MAXSTRING];
	printf("Enter the department name to add the course: ");
	getchar();
	fgets(deptname, MAXSTRING, stdin);
	deptname[strcspn(deptname, "\n")] = 0;
	for( i = 0; i < deptcount; i++){
		if(strcmp(departments[i].deptname, deptname) == 0){
			if(departments[i].coursecount >= MAXCOURSES){
				printf("Maximum number of courses reached for this department.\n");
				return;
			}
			Course newC;
			printf("Enter course ID: ");
			scanf("%d", &newC.courseID);
			printf("Enter course name: ");
			getchar(); 
			fgets(newC.coursename, MAXSTRING, stdin);
			newC.coursename[strcspn(newC.coursename, "\n")] = 0;
			printf("Enter instructor name: ");
			fgets(newC.instructor, MAXSTRING, stdin);
			newC.instructor[strcspn(newC.instructor, "\n")] = 0;
			printf("Enter credits: ");
			scanf("%d", &newC.credits);
			departments[i].courses[departments[i].coursecount++] = newC;
			printf("Course added to department: %s\n", deptname);
			return;
		}
	}
	printf("Department not found.\n");
}
void displaycourses(Department departments[], int deptcount){
	int i, j;
	if(deptcount == 0){
		printf("No departments available.\n");
		return;
	}
	for( i = 0; i < deptcount; i++){
		printf("\nDepartment: %s\n", departments[i].deptname);
		if(departments[i].coursecount == 0){
			printf("No courses available in this department.\n");
		} 
		else{
			for( j = 0; j < departments[i].coursecount; j++){
				Course course = departments[i].courses[j];
				printf("Course ID: %d, Course Name: %s, Instructor: %s, Credits: %d\n",
					course.courseID, course.coursename, course.instructor, course.credits);
			}
		}
	}
}
int main(){
	Department departments[MAXDEPTS];
	int deptcount = 0;
	int choice;
	do{
		printf("\nUniversity Course Enrollment System\n");
		printf("1. Add Department\n");
		printf("2. Add Course to Department\n");
		printf("3. Display Courses in Departments\n");
		printf("4. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		printf("____________________________________\n");
		switch(choice){
			case 1:
				adddept(departments, &deptcount);
				printf("____________________________________\n");
				break;
			case 2:
				addcourse(departments, deptcount);
				printf("____________________________________\n");
				break;
			case 3:
				displaycourses(departments, deptcount);
				printf("____________________________________\n");
				break;
			case 4:
				printf("Exiting program.\n");
				break;
			default:
				printf("Invalid choice. Please try again.\n");
				printf("____________________________________\n");
		}
	}while(choice != 4);
	return 0;
}

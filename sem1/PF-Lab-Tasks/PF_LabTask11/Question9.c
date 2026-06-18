#include <stdio.h>
#include <string.h>
#define MAX_DEPARTMENTS 5
#define MAX_COURSES 10
#define MAX_STUDENTS 50
typedef struct{
	int id;
	char name[50];
}student;
typedef struct{
	int id;
	char name[50];
	char instructor[50];
	int credits;
	int student_count;
	student students[MAX_STUDENTS];
}course;
typedef struct{
	int id;
	char name[50];
	int course_count;
	course courses[MAX_COURSES];
}department;
typedef struct{
	int department_count;
	department departments[MAX_DEPARTMENTS];
}university;
department *finddept(university *uni, int dept_id){
	int i;
	for(i = 0; i < uni->department_count; i++){
		if(uni->departments[i].id == dept_id){
			return &uni->departments[i];
		}
	}
	return NULL;
}
course *findcrs(department *dept, int course_id){
	int i;
	for(i = 0; i < dept->course_count; i++){
		if(dept->courses[i].id == course_id){
			return &dept->courses[i];
		}
	}
	return NULL;
}
void adddept(university *uni){
	if(uni->department_count >= MAX_DEPARTMENTS){
		printf("Maximum number of departments reached.\n");
		return;
	}
	department *dept = &uni->departments[uni->department_count];
	printf("Enter department name: ");
	getchar();
	fgets(dept->name, sizeof(dept->name), stdin);
	dept->name[strcspn(dept->name, "\n")] = '\0';

	printf("Enter department ID: ");
	scanf("%d", &dept->id);

	dept->course_count = 0;
	uni->department_count++;
	printf("Department added successfully.\n");
}
void addcrs(university *uni){
	if(uni->department_count == 0){
		printf("No departments available. Add a department first.\n");
		return;
	}
	int dept_id;
	printf("Enter department ID to add a course: ");
	scanf("%d", &dept_id);
	department *dept = finddept(uni, dept_id);
	if(!dept){
		printf("Invalid department ID.\n");
		return;
	}
	if(dept->course_count >= MAX_COURSES){
		printf("Maximum number of courses for this department reached.\n");
		return;
	}
	course *crs = &dept->courses[dept->course_count];
	crs->id = dept->course_count + 1;
	printf("Enter course name: ");
	getchar();
	fgets(crs->name, sizeof(crs->name), stdin);
	crs->name[strcspn(crs->name, "\n")] = '\0';
	printf("Enter instructor name: ");
	fgets(crs->instructor, sizeof(crs->instructor), stdin);
	crs->instructor[strcspn(crs->instructor, "\n")] = '\0';
	printf("Enter course credits: ");
	scanf("%d", &crs->credits);
	crs->student_count = 0;
	dept->course_count++;
	printf("Course added successfully to %s department.\n", dept->name);
}
void enroll(university *uni){
	if(uni->department_count == 0){
		printf("No departments available. Add a department first.\n");
		return;
	}
	int dept_id, course_id;
	printf("Enter department ID: ");
	scanf("%d", &dept_id);
	department *dept = finddept(uni, dept_id);
	if(!dept){
		printf("Invalid department ID.\n");
		return;
	}
	if(dept->course_count == 0){
		printf("No courses available in this department.\n");
		return;
	}
	printf("Enter course ID: ");
	scanf("%d", &course_id);
	course *crs = findcrs(dept, course_id);
	if(!crs){
		printf("Invalid course ID.\n");
		return;
	}
	if(crs->student_count >= MAX_STUDENTS){
		printf("Maximum number of students for this course reached.\n");
		return;
	}
	student *stu = &crs->students[crs->student_count];
	stu->id = crs->student_count + 1;
	printf("Enter student name: ");
	getchar();
	fgets(stu->name, sizeof(stu->name), stdin);
	stu->name[strcspn(stu->name, "\n")] = '\0';
	crs->student_count++;
	printf("Student enrolled successfully in %s course.\n", crs->name);
}
void displaydata(university uni){
	int i, j, k;
	if(uni.department_count == 0){
		printf("No departments available.\n");
		return;
	}
	printf("\nUniversity Data:\n");
	for(i = 0; i < uni.department_count; i++){
		department dept = uni.departments[i];
		printf("Department %d: %s\n", dept.id, dept.name);

		if(dept.course_count == 0){
			printf("\tNo courses available.\n");
			continue;
		}
		for(j = 0; j < dept.course_count; j++){
			course crs = dept.courses[j];
			printf("\tCourse %d: %s\n", crs.id, crs.name);
			printf("\t\tInstructor: %s\n", crs.instructor);
			printf("\t\tCredits: %d\n", crs.credits);
			printf("\t\tEnrolled Students: %d\n", crs.student_count);
			for(k = 0; k < crs.student_count; k++){
				student stu = crs.students[k];
				printf("\t\t\tStudent %d: %s\n", stu.id, stu.name);
			}
		}
	}
}
int main(){
	university uni;
	uni.department_count = 0;
	int choice;
	while(1){
		printf("University Management System\n");
		printf("1. Add Department\n");
		printf("2. Add Course to Department\n");
		printf("3. Enroll Student in Course\n");
		printf("4. Display University Data\n");
		printf("5. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		printf("___________________\n");
		switch(choice){
			case 1:
				adddept(&uni);
				printf("___________________\n");
				break;
			case 2:
				addcrs(&uni);
				printf("___________________\n");
				break;
			case 3:
				enroll(&uni);
				printf("___________________\n");
				break;
			case 4:
				displaydata(uni);
				printf("___________________\n");
				break;
			case 5:
				printf("Exiting program.\n");
				printf("___________________\n");
				return 0;
			default:
				printf("Invalid choice. Please try again.\n");
				printf("___________________\n");
		}
	}
	return 0;
}

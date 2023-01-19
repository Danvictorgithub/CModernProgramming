#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFERSIZE 100

struct Address {
	char CN[100];
	char CITY[100];
	char BRGY[100];
	char STRT[100];
};
struct Employee {
	char fName[BUFFERSIZE];
	char mInitial;
	char lName[BUFFERSIZE];
	int Age;
	char Position[100];
	int Salary;
	struct Address address;
};
// Step 6

// Step 7
void searchEmployee(struct Employee list[], int numEmployee) {
	char searchName[BUFFERSIZE];
	printf("Enter Name: ");
	scanf(" %[^\n]s",searchName);
	for (int i = 0; i < numEmployee;i++) {
		if (strcmp(searchName,list[i].fName) == 0) {
			printf("%s",list[i].fName);
		}
	}
}
void modifyEmployeeSalary(struct Employee *list,int numEmployee) {
	for (int i = 0; i < numEmployee;i++) {
		list[i].Salary = 5000;
	}
}
void printSalary(struct Employee list[], int numEmployee) {
	for (int i = 0; i < numEmployee; i++) {
		printf("%d\n",list[i].Salary);
	}
}
int main(void) {
	struct Employee employees[BUFFERSIZE];
	FILE *EmployeeDatabase = fopen("Employee.txt","r");
	FILE *SalaryDatabase = fopen("Salary.txt","r");
	char key[BUFFERSIZE];
	char value[BUFFERSIZE];
	int numEmployee;
	int status;
	int i = 0;
	// scanf("%d",&numEmployee);
	if (EmployeeDatabase == NULL) {
		printf("Database unable to load");
		exit(EXIT_FAILURE);
	}
	else {
		// Database Initialization
		while(fscanf(EmployeeDatabase, "%s %s %c %s",key,employees[i].fName,&employees[i].mInitial,employees[i].lName) !=EOF && fscanf(SalaryDatabase,"%s %d",key,&employees[i].Salary) != EOF) {
			i++;
		}
		// searchEmployee(employees,i);
		modifyEmployeeSalary(employees,i);
		printSalary(employees,i);
	}
	return 0;
}

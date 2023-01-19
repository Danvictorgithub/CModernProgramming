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
void employeewith10kSalary(struct Employee *employees, int employeeNum) {
	for (int i = 0; i < employeeNum; i++) {
		if (employees[i].Salary > 10000) {
			printf("%s %c %s has %d worth of Salary\n",
				employees[i].fName,
				employees[i].mInitial,
				employees[i].lName,
				employees[i].Salary
			);
		}
	}
}
// Step 7
void searchEmployee(struct Employee list[], int numEmployee) {
	char searchName[BUFFERSIZE];
	printf("Enter First Name to Search an employee: ");
	scanf(" %[^\n]s",searchName);
	for (int i = 0; i < numEmployee;i++) {
		if (strcmp(searchName,list[i].fName) == 0) {
			printf("Employee Found:\n");
			printf("\tFirst Name: %s\n",list[i].fName);
			printf("\tMiddle Initial: %c\n",list[i].mInitial);
			printf("\tLast Name: %s\n",list[i].lName);
			return;
		}
	}
	printf("Not Found");
}
// Step 8
void modifyEmployeeSalary(struct Employee *list,int numEmployee, int setSalary) {
	for (int i = 0; i < numEmployee;i++) {
		list[i].Salary = setSalary;
	}
}
// Step 8 Helper Function
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
		employeewith10kSalary(employees,i);
		// searchEmployee(employees,i);
		// modifyEmployeeSalary(employees,i,5000);
		// printSalary(employees,i);
	}
	return 0;
}

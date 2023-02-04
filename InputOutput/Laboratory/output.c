#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
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
	int found = 0;
	for (int i = 0; i < numEmployee;i++) {
		if (strcmp(searchName,list[i].fName) == 0) {
			printf("Employee Found:\n");
			printf("\tFirst Name: %s\n",list[i].fName);
			printf("\tMiddle Initial: %c\n",list[i].mInitial);
			printf("\tLast Name: %s\n",list[i].lName);
			printf("\tAge: %d\n",list[i].Age);
			printf("\tFull Address: %s %s %s %s\n",list[i].address.CN,list[i].address.CITY,list[i].address.BRGY,list[i].address.STRT);
			found = 1;
		}
	}
	if (found == 0) {
		printf("Not Found");
	}
}
// Step 8
void modifyEmployeeSalary(struct Employee *list,int numEmployee, int setSalary) {
	for (int i = 0; i < numEmployee;i++) {
		list[i].Salary = setSalary;
	}
	printf("Modified! Please Print Salary to check");
}
// Step 8 Helper Function
void printSalary(struct Employee list[], int numEmployee) {
	for (int i = 0; i < numEmployee; i++) {
		printf("%d\n",list[i].Salary);
	}
}
// Step 9
void printuniquePosition(struct Employee list[], int numEmployee) {
	char *uniquePosition[5];
	char *tempPosition;
	int uniquePositionCounter = 0;
	int alreadyExitFlag = 0;
	for (int i = 0; i < numEmployee; i++) {
		alreadyExitFlag = 0;
		for (int j = 0; j < uniquePositionCounter ;j++) {
			if (strcmp(uniquePosition[j],list[i].Position) == 0) {
				alreadyExitFlag = 1;
			}
		}
		if (!alreadyExitFlag) {
			// printf("Adding %s\n",list[i].Position);
			tempPosition = malloc(sizeof(char) * strlen(list[i].Position));
			strcpy(tempPosition,list[i].Position);
			uniquePosition[uniquePositionCounter] = tempPosition;
			uniquePositionCounter++;
		}
	}
	printf("There are %d Unique Positions:\n",uniquePositionCounter);
	for (int i = 0; i < numEmployee; i++) {
		printf("\t%s\n",uniquePosition[i]);
	}
}
// Step 9 Helper Function
void printPosition(struct Employee list[], int numEmployee) {
	for (int i = 0; i < numEmployee; i++) {
		printf("%s\n",list[i].Position);
	}
}
int main(void) {
	struct Employee employees[BUFFERSIZE];
	FILE *EmployeeDatabase = fopen("Employee.txt","r");
	FILE *SalaryDatabase = fopen("Salary.txt","r");
	FILE *PositionDatabase = fopen("Position.txt","r");
	FILE *AgeDatabase = fopen("Age.txt","r");
	FILE *AddressDatabase = fopen("Address.txt","r");
	char key[BUFFERSIZE];
	int option;
	int i = 0;
	// scanf("%d",&numEmployee);
	if (EmployeeDatabase == NULL) {
		printf("Database unable to load");
		exit(EXIT_FAILURE);
	}
	else {
		// Database Initialization
		while(fscanf(EmployeeDatabase, "%s %s %c %s",key,employees[i].fName,&employees[i].mInitial,employees[i].lName) !=EOF && fscanf(SalaryDatabase,"%s %d",key,&employees[i].Salary) != EOF && fscanf(PositionDatabase,"%s %s",key,employees[i].Position) != EOF && fscanf(AgeDatabase,"%s %d",key,&employees[i].Age) != EOF && fscanf(AddressDatabase,"%s %s %s %s %s",key,employees[i].address.CN,employees[i].address.CITY,employees[i].address.BRGY,employees[i].address.STRT) != EOF) {
			i++;
		}
		do {
			system("cls");
			printf("1. Show Employees with 10k Salary\n");
			printf("2. Search Employee by First Name\n");
			printf("3. Modify Employee Salaries to 5000\n");
			printf("4. Print All Unique Positions\n");
			printf("5. Print Salary\n");
			printf("\t0 to stop\n");
			printf("Enter Options: ");
			scanf("%d",&option);
			switch(option) {
				case 1:
					system("cls");
					employeewith10kSalary(employees,i);
					getch();
					break;
				case 2:
					system("cls");
					searchEmployee(employees,i);
					getch();
					break;
				case 3:
					system("cls");
					modifyEmployeeSalary(employees,i,5000);
					getch();
					break;
				case 4:
					system("cls");
					printuniquePosition(employees,i);
					getch();
					break;
				case 5:
					system("cls");
					printSalary(employees,i);
					getch();
					break;
			}
		}while(option != 0);		
	}
	return 0;
}

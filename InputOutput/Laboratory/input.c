#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Address {
	char CN[100];
	char CITY[100];
	char BRGY[100];
	char STRT[100];
};
struct Employee {
	char fName[100];
	char mInitial;
	char lName[100];
	int Age;
	char Position[100];
	int Salary;
	struct Address address;
};
// Creates Dynamic Array
int getEmployeeNum() {
	int employeeNum = 0;
	do {
		printf("Enter How many Employee do you want to Input [minimum of 3 and maximum of 5]: "),scanf("%d",&employeeNum);
		system("cls");
	} while (employeeNum < 3 || employeeNum > 5);
	
	return employeeNum;
}
struct Employee *genEmployeeArray(int employeeNum) {
	struct Employee *employeelist = malloc(sizeof(struct Employee) * employeeNum);
	return employeelist;
}
void getEmployeeInput(struct Employee *employees,int employeeNum) {
	for (int i = 0; i < employeeNum; i++) {
			printf("[%d] Enter First Name: ",i+1);
			scanf(" %[^\n]s",employees[i].fName);
			system("cls");

			printf("[%d] Enter Middle Initial: ",i+1);
			scanf(" %c",&employees[i].mInitial);
			system("cls");

			printf("[%d] Enter Last Name: ",i+1);
			scanf(" %s[^\n]s",employees[i].lName);
			system("cls");

			printf("[%d] Age: ",i+1);
			scanf("%d",&employees[i].Age);
			system("cls");

			printf("[%d] Position: ",i+1);
			scanf(" %[^\n]s",employees[i].Position);
			system("cls");

			printf("[%d] Salary: ",i+1);
			scanf("%d",&employees[i].Salary);
			system("cls");

			printf("[%d] Country: ",i+1);
			scanf(" %[^\n]s",employees[i].address.CN);
			system("cls");

			printf("[%d] City/Municipality: ",i+1);
			scanf(" %[^\n]s",employees[i].address.CITY);
			system("cls");

			printf("[%d] Barangay: ",i+1);
			scanf(" %[^\n]s",employees[i].address.BRGY);
			system("cls");

			printf("[%d] Street: ",i+1);
			scanf(" %[^\n]s",employees[i].address.STRT);
			system("cls");
		}
}
int main(void) {
	//Loading Databases
	FILE *EmployeeDatabase = fopen("Employee.txt","w");
	FILE *AgeDatabase = fopen("Age.txt","w");
	FILE *PositionDatabase = fopen("Position.txt","w");
	FILE *SalaryDatabase = fopen("Salary.txt","w");
	FILE *AddressDatabase = fopen("Address.txt","w");
	// Functional Dynamic Employee Structure
	int numOfEmployee = getEmployeeNum();
	struct Employee *employees = genEmployeeArray(numOfEmployee);

	if (EmployeeDatabase == NULL || AgeDatabase == NULL || PositionDatabase == NULL || SalaryDatabase == NULL || AddressDatabase == NULL) {
		printf("Failed to open Database");
		exit(EXIT_FAILURE);
	}
	else {
		getEmployeeInput(employees,numOfEmployee);
		// Inputs Data to respective Database
		for (int i = 0; i < numOfEmployee; i++) {
			fprintf(EmployeeDatabase,"Full_Name: %s %c %s\n",
				employees[i].fName, 
				employees[i].mInitial,
				employees[i].lName
			);
			fprintf(AddressDatabase,"Full_Address: %s %s %s %s\n",
				employees[i].address.CN,
				employees[i].address.CITY,
				employees[i].address.BRGY,
				employees[i].address.STRT
			);
			fprintf(AgeDatabase,"Age: %d\n",employees[i].Age);
			fprintf(PositionDatabase, "Position: %s\n",employees[i].Position);
			fprintf(SalaryDatabase,"Salary: %d\n",employees[i].Salary);
		}
		// Closes Databases
		fclose(EmployeeDatabase);
		fclose(AgeDatabase);
		fclose(PositionDatabase);
		fclose(SalaryDatabase);
		fclose(AddressDatabase);
	}
	return 0;
}
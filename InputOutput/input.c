#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Employee Input
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
int main(void) {
	FILE *EmployeeDatabase = fopen("Employee.txt","a");
	FILE *AgeDatabase = fopen("Age.txt","a");
	FILE *PositionDatabase = fopen("Position.txt","a");
	FILE *SalaryDatabase = fopen("Salary.txt","a");
	FILE *AddressDatabase = fopen("Address.txt","a");

	struct Employee employees[3];
	if (EmployeeDatabase == NULL || AgeDatabase == NULL || PositionDatabase == NULL || SalaryDatabase == NULL || AddressDatabase == NULL) {
		printf("Failed to open Database");
		exit(EXIT_FAILURE);
	}
	else {
		for (int i = 0; i < 3; i++) {
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

			// printf("[%d] Enter Country: ",i+1);
			// scanf(" %[^\n]s",employees[i].address.CN);
			// system("cls");
			// system("cls");
			// printf("[%d] Enter Full Address: ",i+1);
			// scanf(" %[^\n]s",employees[i].address.fullAddress);
			// system("cls");
		}
		for (int i = 0; i < 3; i++) {
			// fprintf(fp,"\nFirst Name: %s\nMiddle Initial: %c\nLast Name: %s\nFull Address: %s\n", employees[i].fName, employees[i].mInitial,employees[i].lName,employees[i].address.fullAddress);
			fprintf(EmployeeDatabase,"FullName: %s %c %s\n",employees[i].fName, employees[i].mInitial,employees[i].lName);
			fprintf(AgeDatabase,"Age: %d\n\n",employees[i].Age);
			fprintf(PositionDatabase, "Position: %s\nn",employees[i].Position);
			fprintf(SalaryDatabase,"Salary: %d\n",employees[i].Salary);
		}
		fclose(EmployeeDatabase);
		fclose(AgeDatabase);
		fclose(PositionDatabase);
		fclose(SalaryDatabase);
		fclose(AddressDatabase);
		
	}
	return 0;
}
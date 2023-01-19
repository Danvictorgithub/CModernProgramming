#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Address {
	char fullAddress[100];
};
struct Employee {
	char fName[100];
	char mInitial;
	char lName[100];
	struct Address address;
};
int main(void) {
	FILE *EmployeeDatabase = fopen("Employee.txt","a");
	FILE *AgeDatabase = fopen("Age.txt","a");
	

	struct Employee employees[3];
	if (fp == NULL) {
		printf("File Failed to open");
		exit(EXIT_FAILURE);
	}
	else {
		for (int i = 0; i < 3; i++) {
			printf("Employee[%d]\n",i+1);
			printf("Enter First Name: ");
			scanf(" %[^\n]s",employees[i].fName);
			system("cls");
			printf("Enter Middle Initial: ");
			scanf(" %c",&employees[i].mInitial);
			system("cls");
			printf("Enter Last Name: ");
			scanf(" %s[^\n]s",employees[i].lName);
			system("cls");

			printf("Enter Full Address: ");
			scanf(" %[^\n]s",employees[i].address.fullAddress);
			system("cls");
		}
		for (int i = 0; i < 3; i++) {
			// fprintf(fp,"\nFirst Name: %s\nMiddle Initial: %c\nLast Name: %s\nFull Address: %s\n", employees[i].fName, employees[i].mInitial,employees[i].lName,employees[i].address.fullAddress);
			
		}
		fclose(fp);

		
	}
	return 0;
}
#include <stdio.h>
#include <string.h>
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
	FILE *fp = fopen("C:/Users/Dan/Desktop/CProgramming/CModernProgramming/InputOutput/database.txt","a");
	struct Employee employees[3];
	if (fp == NULL) {
		printf("File Failed to open");
	}
	else {
		for (int i = 0; i < 3; i++) {
			printf("Employee[%d]\n",i+1);
			printf("Enter First Name: ");
			scanf(" %[^\n]s",employees[i].fName);
			printf("Enter Middle Initial: ");
			scanf(" %c",&employees[i].mInitial);
			printf("Enter Last Name: ");
			scanf(" %s[^\n]s",employees[i].lName);

			printf("Enter Full Address: ");
			scanf(" %[^\n]s",employees[i].address.fullAddress);
		}
		for (int i = 0; i < 3; i++) {
			fprintf(fp,"\nFirst Name: %s\nMiddle Initial: %c\nLast Name: %s\nFull Address: %s\n", employees[i].fName, employees[i].mInitial,employees[i].lName,employees[i].address.fullAddress);
		}
		fclose(fp);
	}
	return 0;
}
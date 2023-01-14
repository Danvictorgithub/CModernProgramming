#include <stdio.h>

struct student {
	int rollNumber;
	char name[50];
	char department[50];
	char course[50];
	int yearOfJoining;
};
void findStudent(struct student studentList[], int noStudent, int matchNumber) {
	int i;
	for (i = 0; i < noStudent;i++) {
		if (studentList[i].rollNumber == matchNumber) {
			printf("Found Student with roll Number [%d]:\n",matchNumber);
			printf("%s",studentList[i].name);
		}
	}
}
int main(void) {
	struct student studentList[450];
	int i, numStudent = 2;
	for (i = 0; i < numStudent; i++) {
		printf("Enter Student Information for student %d\n",i);
		printf("Roll Number: ");
		scanf("%d", &studentList[i].rollNumber);
		printf("Student Name: ");
		scanf(" %[^\n]s",studentList[i].name);
		printf("Department Name: ");
		scanf(" %[^\n]s",studentList[i].department);
		printf("Course Name: ");
		scanf(" %[^\n]s",studentList[i].course);
		printf("Year of Joining: ");
		scanf("%d",&studentList[i].yearOfJoining);
	}
	printf("\n");
	return 0;
}
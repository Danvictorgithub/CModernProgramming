#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define LENSTR 100
struct StudentWorks {
	int quizzesScores[5];
	int prelimScore;
	int midtermScore;
	int finalsScore;
};
struct Classroom {
	int studentid;
	char fName[LENSTR];
	char mName[LENSTR];
	char lName[LENSTR];
	int age;
	char contactNumber[LENSTR];
	struct StudentWorks studentScores[5];
	int studentRating;
};
int getNumStudent() {
	int numStudent;
	do {
		printf("Enter Number of Students [minimum of 3 and maximum of 5]: ");
		scanf("%d",&numStudent);
	}while (numStudent < 3 || numStudent > 5);
	
	system("cls");
	return numStudent;
}
void inputStudentData(struct Classroom studentList[],int noStudent) {
	for (int i = 0; i < noStudent;i++) {
	// No.1 
	// 	struct StudentWorks {
	// 	int quizzesScores[5];
	// 	int prelimScore;
	// 	int midtermScore;
	// 	int finalsScore;
	// };
	// struct Classroom {
	// 	int studentid;
	// 	char fName[LENSTR];
	// 	char mName[LENSTR];
	// 	int age;
	// 	int contactNumber;
	// 	struct StudentWorks studentScores[5];
	// };
		printf("[%d]Enter Student ID: ",i+1);
		scanf("%d",&studentList[i].studentid);
		system("cls");

		printf("[%d]Enter Student First Name: ",i+1);
		scanf(" %[^\n]s",studentList[i].fName);
		system("cls");

		printf("[%d]Enter Student Middle Name: ",i+1);
		scanf(" %[^\n]s",studentList[i].mName);
		system("cls");

		printf("[%d]Enter Student Last Name: ",i+1);
		scanf(" %[^\n]s",studentList[i].lName);
		system("cls");		

		printf("[%d]Enter Student Age: ",i+1);
		scanf("%d",&studentList[i].age);
		system("cls");

		printf("[%d]Enter Student Contact Number: ",i+1);
		scanf(" %[^\n]s",studentList[i].contactNumber);
		printf("The number inputted is: %li",studentList[i].contactNumber);
		system("cls");

		for (int j = 0; j < 5;j++) {
			printf("[%d]Student Score on Quiz[%d]: ",i+1,j+1);
			scanf(" %d",&studentList[i].studentScores->quizzesScores[j]);
			// printf("value is: %d\n",studentList[i].studentScores->quizzesScores[j]);
			system("cls");
		}

		printf("[%d]Enter Student Prelim Score: ",i+1);
		scanf("%d",&studentList[i].studentScores->prelimScore);
		system("cls");

		printf("[%d]Enter Student Midterm Score: ",i+1);
		scanf("%d",&studentList[i].studentScores->midtermScore);
		system("cls");

		printf("[%d]Enter Student Finals Score: ",i+1);
		scanf("%d",&studentList[i].studentScores->finalsScore);
		system("cls");
	}
} 
void showListStudent(struct Classroom studentList[],int noStudent) {
	for (int i = 0; i < noStudent;i++) {
		printf("Student Full Name: %s %s. %s\n",studentList[i].fName,studentList[i].mName,studentList[i].lName);
		printf("Age: %d ContactNumber: %s\n",studentList[i].age,studentList[i].contactNumber);
		printf("Scores:\n");
		for (int j = 0; j < 5;j++) {

			printf("Quiz[%d]: %d\n",i+1,studentList[i].studentScores->quizzesScores[j]);
		}
		printf("Prelim Score: %d Midterm Score: %d Finals Score: %d\n",studentList[i].studentScores->prelimScore,studentList[i].studentScores->midtermScore,studentList[i].studentScores->finalsScore);
	}
}
int findAverage(struct Classroom student) {
	int quizScore = 0;
	for (int i = 0; i < 5;i++) {
		quizScore += student.studentScores->quizzesScores[i];
	}
	quizScore = quizScore / 5;
	return quizScore;
}
void searchStudent(struct Classroom studentList[], int noStudent) {
	char searchStudent[LENSTR];
	printf("Enter Student Last Name you want to Search: ");
	scanf(" %[^\n]s",searchStudent);
	printf("Finding %s\n",searchStudent);\
	int flagFound = 0;
	for (int i = 0; i < noStudent;i++) {
		if (strcmp(searchStudent,studentList[i].lName) == 0) {
			printf("Found Student:\n");
			printf("Quiz Score Average: %d\n",findAverage(studentList[i]));
			printf("Prelim Score: %d Midterm Score: %d Finals Score: %d\n",studentList[i].studentScores->prelimScore,studentList[i].studentScores->midtermScore,studentList[i].studentScores->finalsScore);
			flagFound = 1;
			break;
		}
	}
	if (flagFound == 0) {
		printf("Student not Found");
	}
}
void SetstudentRating(struct Classroom studentList[], int noStudent) {
	for (int i = 0; i < noStudent;i++) {
		studentList[i].studentRating = (int)((((float)findAverage(studentList[i])/50.0)*30.0) + ((((float)studentList[i].studentScores->prelimScore + (float)studentList[i].studentScores->midtermScore + (float)studentList[i].studentScores->finalsScore)/3)/60.0)*70.0);
	}
}
void printStudentRating(struct Classroom studentList[], int noStudent) {
	for (int i = 0; i < noStudent;i++) {
		printf("Student Rating: %d\n",studentList[i].studentRating);
	}
}
void bubbleSort(int array[], int arraySize) {
	int swapped = 0;
	int temp;
	for (int i = 0; i < arraySize - 1;i++) {
		if (array[i] < array[i+1]) {
			swapped = 1;
			temp = array[i];
			array[i] = array[i+1];
			array[i+1] = temp;
		}
	}
	if (swapped == 1) {
		bubbleSort(array, arraySize);
	}
}
void rankStudents(struct Classroom studentList[], int noStudent) {
	int studentRatings[noStudent];
	for (int i = 0; i < noStudent;i++) {
		studentRatings[i] = studentList[i].studentRating;
	}
	for (int i = 0; i < noStudent; i++) {
		printf("%d\n", studentRatings[i]);
	}
	printf("Sorted\n");
	bubbleSort(studentRatings, noStudent);
	for (int i = 0; i < noStudent; i++) {
		for (int j = 0; j < noStudent;j++) {
			if (studentRatings[i] == studentList[j].studentRating) {
				printf("Rank[%d] %s %s %s\n",i+1,studentList[j].fName,studentList[j].mName,studentList[j].lName);
			}
		}
	}
}
int main(void) {
	// No time implementing Dynamic Struct 
	FILE *studentDatabase = fopen("Students.txt","w");
	int numStudent = getNumStudent();
	struct Classroom students[numStudent];
	int option;
	// int numStudent = 1;
	// int noStudentFlag = 1;
	// int numStudent;
	// inputStudentData(students,numStudent);
	// SetstudentRating(students,numStudent);
	// printStudentRating(students,numStudent);
	// showListStudent(students,numStudent);
	// printStudentRating(students,numStudent);
	// rankStudents(students,numStudent);
	// printf("1. Add Students data\n");
	// printf("2. Display the list of students");
	// printf("3. Searchs a student last names and displays the students average long quiz exam and major exams score\n");
	// printf("4. Show ranking of students\n");
	// printf("5. Save Students information to a text file\n");
	// printf("Enter Option: ");
	// scanf("%d",&option);
	while (1) {
		printf("1. Add Students data\n");
		printf("2. Display the list of students\n");
		printf("3. Searchs a student last names and displays the students average long quiz exam and major exams score\n");
		printf("4. Show ranking of students\n");
		printf("5. Save Students information to a text file\n");
		printf("Enter Option: ");
		scanf("%d",&option);
		switch (option) {
			case 1:
				system("cls");
				inputStudentData(students,numStudent);
				SetstudentRating(students,numStudent);
				break;
			case 2:
				system("cls");
				showListStudent(students,numStudent);
				break;
			case 3:
				system("cls");
				searchStudent(students,numStudent);
			case 4:
				system("cls");
				rankStudents(students,numStudent);
			case 5:
				for (int i = 0; i < numStudent;i++) {
					fprintf(studentDatabase,"FullName: %s %s %s StudentID: %d Age: %d ContactNumber: %s QuizAverage: %d Prelims_Score: %d Midterms_Score: %d Finals_Score: %d\n",
						students[i].fName,students[i].mName,students[i].lName,
						students[i].studentid,students[i].age,students[i].contactNumber,
						findAverage(students[i]),students[i].studentScores->prelimScore,students[i].studentScores->midtermScore,students[i].studentScores->finalsScore
					);
				}
				printf("Saved!");
				getch();
				system("clr");
				break;
		}
	}
	// searchStudent(students,numStudent);
	//Initializing Database
	return 0;
}
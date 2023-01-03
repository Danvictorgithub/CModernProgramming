#include <stdio.h>
#define FIRST_NAME_LEN 25
#define LAST_NAME_LEN 25
#define STUDENT(n) student##n
struct part {
	int number;
} part1,part2,part3;
struct person_name {
	char first[FIRST_NAME_LEN+1];
	char middle_initial;
	char last[LAST_NAME_LEN];
};
struct student {
	struct person_name name;
	int id, age;
	char sex;
} student1,student2,student3;

void display_name (struct person_name student_name) {
	printf("%s %c. %s", student_name.first,student_name.middle_initial,student_name.last);
}
int main(void) {
	struct student student1 = {{"Dan Victor", 'B',"Lofranco"},21100842,20,'M'};
	// display_name(student1.name);
	student2 = (struct student){{"Juan", 'L',"Dela Cruz"},21100842,20,'M'};
	// display_name(student2.name);
	student3 = (struct student) {{"Monkey",'D',"Luffy"},21100842,20,'M'};

	struct student studentList[3] = {STUDENT(1),STUDENT(2),STUDENT(3)};
	// for (int i = 0; i < 3; i++) {
	// 	studentList[i] = STUDENT(i);
	// }
	

	for (int i = 0 ; i < 3-1;i++) {
		struct student studentTemp = studentList[i+1];
		studentList[i] = studentList[i+1];
		studentList[i+1] = studentTemp;
		if (i == 2-1) {
			printf("succeed\n");
			studentList[i+1] = (struct student){};
		}
	}
	display_name(studentList[2].name);
	return 0;
}
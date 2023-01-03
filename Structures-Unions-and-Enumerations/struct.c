#include <stdio.h>
#include <string.h>
#define NAME_LEN 25

struct person_name {
	char first[NAME_LEN + 1];
	char middle_initial;
	char last[NAME_LEN + 1];
};
struct student {
	struct person_name name;
	int id, age;
	char sex;
} student1, student2;

int main(void) {
	struct person_name new_name = {"DAN VICTOR", 'B' , "LOFRANCO"};
	student1.name = new_name;
	student1.id = 21100842;
	student1.sex = 'M';
	printf("%s %c %s %d %c", student1.name.first, student1.name.middle_initial, student1.name.last,student1.id,student1.sex);
	return 0;
}
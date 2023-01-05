#include <stdio.h>
#include <string.h>
#define NAME_LEN 25

struct student {
	char name[NAME_LEN+1];
	int id;
};
int main(void) {
	struct student listStudent[] ={
		{"Dan Victor", 81100842},{"Victor Dan",24800118}
	};
	for (int i = 0; i < sizeof(listStudent)/sizeof(listStudent[0]);i++) {
		printf("%s\n",listStudent[i].name);
	}
	return 0;
}
#include <stdio.h>

int main(int argc, char const *argv[])
{
	char *stringList[] = {"dan", "victor", "b", "lofranco"};
	for (int i = 0; i < 4;i++){
		printf("%s",stringList[i]);
	}
	return 0;
}
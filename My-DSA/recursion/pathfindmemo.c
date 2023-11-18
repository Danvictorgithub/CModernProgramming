#include <stdio.h>
int findPath(int x,int y,int path[][3],int memo[][3],int* numPaths) {
	if (path[x][y] == 1) {
		*numPaths += 1;
		printf("%d,%d\n",x,y);
		printf("path found\n");
		return 1;
	}
	if (x == 3 || y == 3) {
		return 0;
	}

	printf("%d,%d\n",x,y);
	if (memo[x+1][y] != -1) {
		memo[x+1][y] = 0;
		findPath(x+1,y,path,memo,numPaths);
	}
	if (memo[x][y+1] != -1) {
		memo[x][y+1] = 0;
		findPath(x,y+1,path,memo,numPaths);
	}
}

int main() {
	int memo[3][3] = {-1};
	int path[3][3] = {
		{0,0,0},
		{0,0,0},
		{0,0,1}
	};
	int numPaths = 0;
	// printf("%d",path[2][2]);
	findPath(0,0,path,memo,&numPaths);
	printf("Number of path: %d\n",numPaths);
	return 0;
}
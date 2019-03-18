#include <stdio.h>

void print5Triangle() {
	int array[5][9] = {{0, 0, 0, 0, 0, 1}, {0, 0, 0, 0 ,1, 2},
					   {0, 0, 0, 1, 2, 3, 4}, {0, 0, 1, 2, 3, 4, 5, 6},
					   {0, 1, 2, 3, 4, 5, 6, 7, 8}};

	int height = 5;
	int i, j;
	for (i = 0; i < height; i++) {
		for (j = 0; j < 9; j++) {
			if (j >= (height - 1 -i) && (j < (height + i))) {
				printf("%d ", array[i][j]);
			}
			else {
				printf("  ");
			}
		}
		printf("\n");
	}
}

int main() {
	print5Triangle();

	return 0;
}
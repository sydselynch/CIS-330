#include <stdio.h>
#include <stdlib.h>


//#define MAXSIZE 40

typedef struct Board {
	int size;
	char** display;
	char p1, p2;
} Board;

typedef enum piece {
	NONE,
	PLAYER1,
	PLAYER2
} Piece;

void clearInputBuffer() {
	// From CIS 330 website
	while ( getchar() != '\n');
}



/*void allocateInitialBoardMemory(Board *board) {
	//board.display = (char*)malloc(sizeof(char) * size);
	//board -> display = (char**)malloc(sizeof(char* ) * board -> size);
	int i;
	char** displayarr = malloc(sizeof(char* ) * board -> size);
	for (i = 0; i < board -> size; i++) {
		displayarr[i] = malloc(sizeof(**displayarr) * board -> size);
	}
}*/

void displayBoard(char** board, int size) {
	int i, j;
	printf("  ");
	for (i = 0; i < size; i++) {
		printf(" %d", i);
	}
	printf("\n");
	for (i = 0; i < size; i++) {
		if (i < 10) {
			printf(" %d", i);
		}
		else {
			printf("%d", i);
		}
		
		for (j = 0; j < size; j++) {
			printf(" %c", board[i][j]);
		}
		printf("\n");
	}



}


int[] validMoves

void updateBoard(char** board, int size, int x, int y, char player) {
	int i, j;
	board[x][y] = player;
	displayBoard(board, size);
}

	

void player1move(char** board, int size) {
	int i, j, x, y;
	char player1 = '@';
	printf("Player 1: Enter a move (x y) ");
	scanf("%d %d", &x, &y);
	updateBoard(board, size, x, y, player1);

}



int isValid(char **arr, x, y, char ){
	

	return 0;
}

void createBoard(int size) {
	Board board;
	//char** displayarr;
	int i, j;
	//int count = 0;
	board.size = size;
	
	// Allocate mem for 2d array
	/*displayarr = malloc(sizeof(char*) * size);
	for (i = 0; i < size; i++) {
		displayarr[i] = malloc(sizeof(char) * size);
	}*/

	board.display = malloc(sizeof(char*) * size);
	for (i = 0; i < size; i++) {
		board.display[i] = malloc(sizeof(char) * size);
	}
	
	// initialize empty board
	printf("  ");
	for (i = 0; i < size; i++) {
		printf(" %d", i);
	}
	printf("\n");
	for (i = 0; i < size; i++) {
		if (i < 10) {
			printf(" %d", i);
		}
		else {
			printf("%d", i);
		}
		
		for (j = 0; j < size; j++) {
			if ((i == size / 2 && j == size / 2) || (i == size / 2 - 1 && j == size / 2 - 1)) {
				board.display[i][j] = '@';
			}
			else if ((i == size / 2  && j == size / 2 - 1) || (i == size / 2 - 1 && j == size / 2)) {
				board.display[i][j] = 'X';
			}
			else {	
				board.display[i][j] = '.';
			}
			printf(" %c", board.display[i][j]);
		}
		printf("\n");
	}

	player1move(board.display, board.size);


	
	
}



int main() {
	int boardSize;
	int valid = 0;

	while (valid == 0) {
		printf("Please enter the size of the board: ");
		if (scanf("%d", &boardSize) == 0) {
			clearInputBuffer();
			printf("The board size must be an integer.\n");
		}

		else if (boardSize < 4 || boardSize > 12 || boardSize % 2 != 0) {
			printf("The board size must be an even integer between 6-10.\n");
		}

		else {
			valid = 1;
		}

	}

	createBoard(boardSize);

}
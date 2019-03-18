#include <stdio.h>
#include <stdlib.h>


void clearInputBuffer() {
	while ( getchar() != '\n');
}


void displayBoard(struct Board board) {
	int i, j;
	printf("  ");
	for (i = 0; i < board.size; i++) {
		printf(" %d", i);
	}
	printf("\n");
	for (i = 0; i < board.size; i++) {
		if (i < 10) {
			printf(" %d", i);
		}
		else {
			printf("%d", i);
		}
		
		for (j = 0; j < board.size; j++) {
			printf(" %c", board.display[i][j]);
		}
		printf("\n");
	}

}


void updateBoard(struct Board board, int row, int col, char player) {
	int i, j;
	board.display[row][col] = player;
}


void flip(struct Board board, int row, int col, int adjrow, int adjcol, char player) {
	int newrow = row - adjrow;
	int newcol = col - adjcol;

	while (newrow >= 0 && newcol >= 0 && newrow < board.size && newcol < board.size) {
		if (board.display[newrow][newcol] != player && board.display[newrow][newcol] != '.') {
			board.display[newrow][newcol] = player;
		}
		newrow -= adjrow;
		newcol -= adjcol;
	}

}

int followPath(struct Board board, int row, int col, int adjrow, int adjcol, char player) {
	int i, j;
	int valid = 0;
	int newrow = adjrow + row;
	int newcol = adjcol + col;
	while (newrow >= 0 && newcol >= 0 && newrow < board.size && newcol < board.size) {
		
		if (board.display[newrow][newcol] == player) {
			flip(board, newrow, newcol, adjrow, adjcol, player);

			return 1;

		}
		else if (board.display[newrow][newcol] == '.') {
			return 0;
		}
		else {
			newrow += adjrow;
			newcol += adjcol;
		}
		
	}

	return 0;
}

		

int isValid(struct Board board, int row, int col, char player) {
	int i, j, adjRow, adjCol;
	int valid = 0;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if ((row + i - 1) >= 0 && (col + j - 1) >= 0 && (row + i - 1) < board.size && (col + j - 1) < board.size) {
				if (board.display[row+i-1][col+j-1] != player && board.display[row+i-1][col+j-1] != '.') {
					adjRow = (row+i-1) - row;
					adjCol = (col+j-1) - col;
					if (followPath(board, row, col, adjRow, adjCol, player) == 1) {
						valid = 1;
					}


				}
			}
		}
	}
	
	return valid;
}



int playerMove(struct Board board, Piece piece) {
	int i, j, row, col, player1pass, player2pass;
	if (piece == 1) {
		printf("Player 1 (%c) enter a move (row col) - If no moves are possible, enter -1 to pass: ", board.p1);
		scanf("%d", &row);
		if (row == -1) {
			return 1;
		}
		scanf("%d", &col);
		if (isValid(board, row, col, board.p1) == 1) {
			updateBoard(board, row, col, board.p1);
		}
		else {
			printf("Invalid move, try again.\n");
			playerMove(board, piece);
		}
	}
	else if (piece == 2) {
		printf("Player 2 (%c) enter a move (row col) - If no moves are possible, enter -1 to pass: ", board.p2);
		scanf("%d", &row);
		if (row == -1) {
			return 1;
		}
		scanf("%d", &col);
		if (isValid(board, row, col, board.p2) == 1) {
			updateBoard(board, row, col, board.p2);
		}
		else {
			printf("Invalid move, try again.\n");
			playerMove(board, piece);
		}
	}
	return -1;
}


Board choosePlayer(struct Board board) {
	char p1, p2;
	printf("Player 1: Choose your piece (one character) ");
	scanf("%c", &p1);
	clearInputBuffer();
	printf("Player 2: Choose your piece (one character) ");
	scanf("%c", &p2);
	clearInputBuffer();
	board.p1 = p1;
	board.p2 = p2;

	return board;
}

int playerScore(Board board, char player) {
	int i, j;
	int score = 0;
	for (i = 0; i < board.size; i++) {
		for (j = 0; j < board.size; j++) {
			if (board.display[i][j] == player) {
				score += 1;
			}
		}
	}
	return score;
}


void beginGame(int size) {
	Board board;
	Piece piece;
	int i, j, numPasses;
	board.size = size;
	board = choosePlayer(board);

	board.display = malloc(sizeof(char*) * size);
	for (i = 0; i < size; i++) {
		board.display[i] = malloc(sizeof(char) * size);
	}
	
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
				board.display[i][j] = board.p1;
			}
			else if ((i == size / 2  && j == size / 2 - 1) || (i == size / 2 - 1 && j == size / 2)) {
				board.display[i][j] = board.p2;
			}
			else {	
				board.display[i][j] = '.';
			}
			printf(" %c", board.display[i][j]);
		}
		printf("\n");
	}

	printf("If a player cannot make a move, pass by entering -1. If both players pass their turn, the game will end.\n");

	while (numPasses < 2) {
		numPasses = 0;
		numPasses += playerMove(board, PLAYER1);
		displayBoard(board);
		printf("Player 1: %d      Player 2: %d\n", playerScore(board, board.p1), playerScore(board, board.p2));
		numPasses += playerMove(board, PLAYER2);
		displayBoard(board);
		printf("Player 1: %d      Player 2: %d\n", playerScore(board, board.p1), playerScore(board, board.p2));
	}

	printf("\n");
	printf("Game over.\nFinal Score - Player 1: %d      Player 2: %d\n", playerScore(board, board.p1), playerScore(board, board.p2));

	for (i = 0; i < size; i++) {
		free((board.display)[i]);
	}
	free(board.display);
	
	
}

int obtainBoardSize() {
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
	
	clearInputBuffer();
	return boardSize;
}


#ifndef REVERSI_H_
#define REVERSI_H_

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

/* Clear the buffer of bad input */
void clearInputBuffer();

/* Output board */
void displayBoard(struct Board board);

/* Update board with new piece */
void updateBoard(struct Board board, int row, int col, char player);

/* Flip in-between pieces */
void flip(struct Board board, int row, int col, int adjrow, int adjcol, char player);

/* Follow input to check validity */
int followPath(struct Board board, int row, int col, int adjrow, int adjcol, char player);

/* Check if input is valid move */
int isValid(struct Board board, int row, int col, char player);

/* Gather player input */
int playerMove(struct Board board, Piece piece);

/* Choose player pieces */
Board choosePlayer(struct Board board);

/* Calculate player scores */
int playerScore(Board board, char player);

/* Start game */
void beginGame(int size);

/* Obtain the board size */
int obtainBoardSize();

#endif /* REVERSI_H_ */
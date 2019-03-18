#include <stdio.h>
#include <stdlib.h>
#include "reversi.h"


int main() {
	int boardSize;
	boardSize = obtainBoardSize();
	beginGame(boardSize);

}
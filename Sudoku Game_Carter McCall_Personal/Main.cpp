/* Carter McCall
*  Main.cpp
*  27 Feb. 2023
*  Purpose:
*		Hold main() function
*/

#include "Board.h"
#include "Colors.h"

int main() {
	Board bd;
	int input;
	cout << ANSI_COLOR_WHITE << "Welcome to sudoku! You will be playing on a 9x9 board, Good Luck!\n\n\n";
	bd.printBoard();
	bd.tempCoordinate();
	bd.printBoard();
	cout << ANSI_COLOR_WHITE;
}
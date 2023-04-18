/* Carter McCall
*  Main.cpp
*  27 Feb. 2023
*  Purpose:
*		Hold main() function
*/

#include "Board.h"

int main() {
	Board bd;
	int input;
	cout << "Welcome to sudoku! Would you like a: 2.) 6x6 board, 3.) 9x9 board ";
	cin >> input;
	input *= 3;
	bd.initializer();
	bd.printThreeByThree(input);
}
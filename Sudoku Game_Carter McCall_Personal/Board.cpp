/* Carter McCall
*  Board.cpp
*  27 Feb. 2023
*  Purpose:
*		Hold the printBoard() and game() functions
*/

#include "Board.h"	
#include "Colors.h"

void Board::printBoard() {

	for (int i = 0; i < 9; i++)	cout << ANSI_COLOR_RED << vertical << spacer;
	cout << vertical << endl;

	for (int i = 0; i < 9; i++) {
		cout << vertical;
		for (int j = 0; j < 9; j++) {
			cout << ANSI_COLOR_WHITE << nineByNine[i][j];
			if (j != 2 && j != 5 && j != 8) cout << ' ';
			else cout << ANSI_COLOR_RED << vertical;
		}
		cout << endl;
		if (i == 2 || i == 5 || i == 8) {
			for (int i = 0; i < 9; i++)	cout << ANSI_COLOR_RED << vertical << spacer;
			cout << vertical << endl;
		}
	}
}
/* Carter McCall
*  Board.cpp
*  27 Feb. 2023
*  Purpose:
*		Hold the printBoard() and game() functions
*/

#include "Board.h"	
#include "Colors.h"

void Board::printBoard() {

	cout << "  ";
	for (int i = 0; i < 9; i++) cout << ANSI_COLOR_BLACK << i + 1 << ' ';		

	cout << "\n ";
	for (int i = 0; i < 9; i++)	cout << ANSI_COLOR_RED << vertical << spacer;
	cout << vertical << endl;

	for (int i = 0; i < 9; i++) {

		if (i == 0) letter = 'A';
		else if (i == 1) letter = 'B';
		else if (i == 2) letter = 'C';
		else if (i == 3) letter = 'D';
		else if (i == 4) letter = 'E';
		else if (i == 5) letter = 'F';
		else if (i == 6) letter = 'G';
		else if (i == 7) letter = 'H';
		else if (i == 8) letter = 'I';

		cout << ANSI_COLOR_BLACK << letter << ANSI_COLOR_RED << vertical;
		for (int j = 0; j < 9; j++) {
			cout << ANSI_COLOR_WHITE << nineByNine[i][j];
			if (j != 2 && j != 5 && j != 8) cout << ' ';
			else cout << ANSI_COLOR_RED << vertical;
		}
		cout << endl;
		if (i == 2 || i == 5 || i == 8) {
			cout << ' ';
			for (int i = 0; i < 9; i++)	cout << ANSI_COLOR_RED << vertical << spacer;
			cout << vertical << endl;
		}
	}
}
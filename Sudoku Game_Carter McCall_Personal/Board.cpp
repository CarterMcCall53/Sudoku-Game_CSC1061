/* Carter McCall
*  Board.cpp
*  27 Feb. 2023
*  Purpose:
*		Hold the printBoard() and game() functions
*/

#include "Board.h"	
#include "Colors.h"

void Board::printThreeByThree(int multiplier) {
	bool check = true;
	for (int i = 0; i < multiplier; i++) {
		if (check == true) {
			cout << ANSI_COLOR_RED << vertical;
			for (int j = 0; j < multiplier; j++) cout << ANSI_COLOR_RED << spacer << vertical << spacer << vertical << spacer << vertical << endl;
			cout << endl;
		}
		cout << vertical;
		for (int j = 0; j < multiplier; j++) {
			cout << ANSI_COLOR_WHITE << threeByThree[j][i] << vertical;
		}
		cout << ANSI_COLOR_RED << vertical;
		cout << endl;
	}
}

void Board::initializer() {
	srand(time(0));

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			threeByThree[j][i] = rand() % 9;
			//cout << threeByThree[j][i];
		}
	}
	//cout << "\nNew Line\n";
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			sixBySix[j][i] = rand() % 9;
			//cout << sixBySix[j][i];
		}
	}
	//cout << "\nNew Line\n";
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			nineByNine[j][i] = rand() % 9;
			//cout << nineByNine[j][i];
		}
	}
}
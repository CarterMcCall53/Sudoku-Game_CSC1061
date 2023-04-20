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

	for (int h = 0; h < 3; h++) {
		for (int g = 0; g < ; g++) {
			cout << vertical;
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 3; j++) {
					cout << ANSI_COLOR_WHITE << nineByNine[i + h][j + g];
					if (j != 2) cout << ' ';
				}
				cout << ANSI_COLOR_RED << vertical;
			}
			cout << endl;
		}
		for (int i = 0; i < 9; i++)	cout << ANSI_COLOR_RED << vertical << spacer;
		cout << vertical << endl;
	}
}

//void Board::initializer() {
//	srand(time(0));
//
//	for (int i = 0; i < 9; i++) {
//		for (int j = 0; j < 9; j++) {
//			nineByNine[j][i] = rand() % 9;
//			//cout << threeByThree[j][i];
//		}
//	}
//}
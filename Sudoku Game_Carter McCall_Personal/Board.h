#pragma once
/* Carter McCall
*  Board.h
*  27 Feb. 2023
*  Purpose:
*		Hold the board class
*/

using namespace std;
#include <iostream>

class Board {
private:
	char spacer = '-', vertical = '|', letter;
	int nineByNine[9][9] = { {1, 2, 3, 4, 5, 6, 7, 8, 9},
							 {2, 3, 4, 5, 6, 7, 8, 9, 1},
							 {3, 4, 5, 6, 7, 8, 9, 1, 2},
							 {4, 5, 6, 7, 8, 9, 1, 2, 3},
							 {5, 6, 7, 8, 9, 1, 2, 3, 4},
							 {6, 7, 8, 9, 1, 2, 3, 4, 5},
							 {7, 8, 9, 1, 2, 3, 4, 5, 6},
							 {8, 9, 1, 2, 3, 4, 5, 6, 7},
							 {9, 1, 2, 3, 4, 5, 6, 7, 8} };
	string letters[26] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q",
					      "r", "s", "t", "u", "v", "w", "x", "y", "z"};
public:
	void printBoard();
	void tempCoordinate();
};



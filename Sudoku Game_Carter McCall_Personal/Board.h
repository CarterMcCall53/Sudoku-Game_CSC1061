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
	string spacer = "-", vertical = "|";
	int nineByNine[9][9] = { {1, 2, 3, 4, 5, 6, 7, 8, 9 },
		{2, 3, 4, 5, 6, 7, 8, 9, 1},
		{3, 4, 5, 6, 7, 8, 9, 1, 2},
		{4, 5, 6, 7, 8, 9, 1, 2, 3},
		{5, 6, 7, 8, 9, 1, 2, 3, 4},
		{6, 7, 8, 9, 1, 2, 3, 4, 5},
		{7, 8, 9, 1, 2, 3, 4, 5, 6},
		{8, 9, 1, 2, 3, 4, 5, 6, 7},
		{9, 1, 2, 3, 4, 5, 6, 7, 8} };

public:
	void printBoard();
	void initializer();
};

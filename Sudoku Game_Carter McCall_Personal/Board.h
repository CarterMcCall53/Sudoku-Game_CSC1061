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
	int threeByThree[3][3], sixBySix[6][6], nineByNine[9][9];

public:
	void printThreeByThree(int multiplier);
	void initializer();
};

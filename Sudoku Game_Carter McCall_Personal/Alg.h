/*Alg.h
*Isaiah Hocking
*21 April 2023
*Purpose:
*		Defining a class to store the board values and variables for the algroythms
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm> 
#include <cmath>

#include "Board.h"
class Alg {
private:
	
	struct Rows {
		vector<int> r;
	};
	int board[9][9] = { {0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0} };

	int output[9][9] ={ {0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0} };
	struct Coord {
		int row = 0;
		int column = 0;
	};
	Rows rows[9];
	void shift(int,int);
	void swapCol(int, int);
public:
	int getoutput(int, int);
	void randomBoard(int);
	//unused
	//int getRow(int,int);
	//int getColumn(int, int);
	int getSquare(int, int);
	int check(int[9][9]);
};
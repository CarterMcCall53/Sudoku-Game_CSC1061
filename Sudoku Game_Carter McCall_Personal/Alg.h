/**/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm> 
#include <cmath>

#include "Board.h"
class Alg {
private:
	vector<int> row[9];
	vector<int> column[9];
	vector<int> square[9];
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
	struct Coord {
		int row = 0;
		int column = 0;
	};
	Rows rows[9];
	void shift(int,int);
	void swapCol(int, int);
public:
	int getNumber(int, int);
	void randomBoard();
	//unused
	//int getRow(int,int);
	//int getColumn(int, int);
	int getSquare(int, int);
	int check(int[9][9]);
};


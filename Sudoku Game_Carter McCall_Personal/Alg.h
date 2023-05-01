/**/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm> 
#include <cmath>

class Alg {
private:
	std::vector<int> row[9];
	std::vector<int> column[9];
	std::vector<int> square[9];
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

public:
	int getNumber(int, int);
	void basicVectors();
	void randomBoard();
	int getRow(int,int);
	int getColumn(int, int);
	int getSquare(int, int);
	int check(int[9][9]);
};


#pragma once
/* Carter McCall & Hosea Masih
*  Board.h
*  27 Feb. 2023
*  Purpose:
*		Hold the board class
*  Progress:
*		Modified: March 20, 2023
*			Added variables and 2d array in the private
*			and updated the public to house the printBoard
*			function
*		Modifed: March 24, 2023 
*			Updated and added the tempCoordinate function
*			to store the method
*		Modified: March 25, 2023
*			Reformated and reorganized to clean up clutter
*/

// included libraries for Board.h
using namespace std;
#include <iostream>

class Board {

	

private:				// stored variables & 2d array for board + special chars

	char spacer = '-', vertical = '|', letter;

	// test coordinate system
	string letters[26] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q",
					      "r", "s", "t", "u", "v", "w", "x", "y", "z"};
	string rowLetter;
	int rowCoordinate;
	int columnCoordinate;
	int input;
public:					 
	
	// printBoard() test array
	int nineByNine[9][9];

	int board1[9][9] = { { 0, 7, 0, 4, 1, 0, 0, 0, 0 },
						 { 0, 0, 0, 0, 0, 0, 9, 7, 4 },
						 { 3, 8, 0, 0, 0, 2, 1, 0, 0 },
						 { 4, 6, 0, 0, 0, 0, 0, 0, 0 },
						 { 0, 0, 9, 0, 0, 5, 0, 4, 0 },
						 { 8, 0, 1, 0, 0, 0, 0, 0, 0 },
						 { 0, 0, 6, 9, 0, 4, 0, 8, 3 },
						 { 0, 0, 3, 2, 0, 0, 0, 1, 0 },
						 { 0, 0, 0, 0, 0, 1, 0, 2, 6 } };

	int board2[9][9] = { { 0, 8, 0, 0, 0, 0, 6, 3, 0 },
						 { 0, 0, 9, 0, 0, 8, 0, 0, 0 },
						 { 0, 0, 0, 0, 9, 7, 0, 0, 0 },
						 { 0, 4, 0, 0, 0, 0, 0, 0, 0 },
						 { 1, 0, 0, 0, 0, 0, 2, 5, 3 },
						 { 5, 0, 6, 2, 0, 0, 0, 4, 0 },
						 { 0, 0, 0, 0, 4, 0, 0, 6, 5 },
						 { 0, 0, 0, 8, 2, 0, 0, 0, 0 },
						 { 0, 0, 8, 9, 5, 1, 4, 0, 0 } };

	int board3[9][9] = { { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
						 { 0, 0, 5, 0, 0, 0, 0, 0, 0 },
						 { 0, 0, 0, 3, 0, 0, 9, 0, 0 },
						 { 0, 0, 0, 0, 0, 4, 0, 0, 0 },
						 { 0, 0, 0, 6, 3, 7, 0, 0, 0 },
						 { 0, 0, 0, 1, 0, 0, 0, 0, 0 },
						 { 0, 0, 7, 0, 0, 8, 0, 0, 0 },
						 { 0, 0, 0, 0, 0, 0, 8, 0, 0 },
						 { 0, 0, 0, 0, 0, 0, 0, 0, 0 } };

	int board4[9][9] = { { 0, 0, 0, 0, 0, 1, 0, 0, 0 },
						 { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
						 { 0, 0, 0, 0, 0, 6, 0, 0, 0 },
						 { 0, 0, 0, 4, 0, 0, 0, 0, 0 },
						 { 0, 0, 0, 0, 8, 0, 0, 0, 0 },
						 { 2, 0, 9, 0, 0, 0, 0, 0, 7 },
						 { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
						 { 0, 0, 0, 0, 0, 3, 0, 0, 0 },
						 { 0, 0, 0, 0, 0, 0, 0, 0, 0 } };

	// houses functions for Board.cpp
	void printBoard(int a [9][9]);
	void coordinate();
	int getNumber(int y, int x);
	void gameplayLoop();
};
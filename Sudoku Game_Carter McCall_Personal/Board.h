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

	// 2d array
	int nineByNine[9][9] = { {1, 2, 3, 4, 5, 6, 7, 8, 9},
							 {2, 3, 4, 5, 6, 7, 8, 9, 1},
							 {3, 4, 5, 6, 7, 8, 9, 1, 2},
							 {4, 5, 6, 7, 8, 9, 1, 2, 3},
							 {5, 6, 7, 8, 9, 1, 2, 3, 4},
							 {6, 7, 8, 9, 1, 2, 3, 4, 5},
							 {7, 8, 9, 1, 2, 3, 4, 5, 6},
							 {8, 9, 1, 2, 3, 4, 5, 6, 7},
							 {9, 1, 2, 3, 4, 5, 6, 7, 8} };

	// variables for printBoard()
	string letters[26] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q",
					      "r", "s", "t", "u", "v", "w", "x", "y", "z"};
	string rowLetter;
	int rowCoordinate;
	int columnCoordinate;
	int input;


	
public:					 // houses functions for Board.cpp
	void printBoard();
	void tempCoordinate();
};



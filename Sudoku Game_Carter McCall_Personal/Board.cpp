/* Carter McCall & Hosea Masih
*  Board.cpp
*  27 Feb. 2023
*  Purpose:
*		Hold the printBoard() and game() functions
*  Progress:
*		Modified: March 20, 2023
*			 Updated the board to add a grid and 2d array to print
*		Modified: March 24, 2023 
*			 Added the coordinate system, using a 1d array
*	    Modified: March 25, 2023
*			Added more organization and reformated the .cpp file
*		
*/

// included libraries for Board.cpp
#include "Board.h"	
#include "Colors.h"

/*
  Prints the board using for loops and the 2d
  array with numbers. Empty space and a special
  chars are used to make the board more organized
  and less cluttered.
*/

void Board::printBoard() {

	cout << "  ";
	for (int i = 0; i < 9; i++) cout << ANSI_COLOR_BLACK << i + 1 << ' ';		

	cout << "\n ";
	for (int i = 0; i < 9; i++)	cout << ANSI_COLOR_RED << vertical << spacer;
	cout << vertical << endl;

	for (int i = 0; i < 9; i++) {

		if (i == 0) letter = 'A';
		else if (i == 1) letter = 'B';
		else if (i == 2) letter = 'C';
		else if (i == 3) letter = 'D';
		else if (i == 4) letter = 'E';
		else if (i == 5) letter = 'F';
		else if (i == 6) letter = 'G';
		else if (i == 7) letter = 'H';
		else if (i == 8) letter = 'I';

		cout << ANSI_COLOR_BLACK << letter << ANSI_COLOR_RED << vertical;
		for (int j = 0; j < 9; j++) {
			cout << ANSI_COLOR_WHITE << nineByNine[i][j];
			if (j != 2 && j != 5 && j != 8) cout << ' ';
			else cout << ANSI_COLOR_RED << vertical;
		}
		cout << endl;
		if (i == 2 || i == 5 || i == 8) {
			cout << ' ';
			for (int i = 0; i < 9; i++)	cout << ANSI_COLOR_RED << vertical << spacer;
			cout << vertical << endl;
		}
	}
}

  /*
  Code to access the board in specific coordinates
  and change the number at that specific coordinate
  Using a 1d array of letters to access the 2d array,
  for the x-coordinate and a int variable to access 
  the y-coordinate
  */

void Board::tempCoordinate() {


	cout << ANSI_COLOR_WHITE << "\nWhat row would you like? ";
	cin >> rowLetter;
	rowLetter = tolower(rowLetter[0]);
	for (int i = 0; i < 26; i++)
	{
		if (rowLetter == letters[i]) rowCoordinate = i;
	}

	cout << "\nWhat column would you like? ";
	cin >> columnCoordinate;
	columnCoordinate -= 1;

	cout << "\nWhat number would you like to input? ";
	cin >> input;

	nineByNine[rowCoordinate][columnCoordinate] = input;
}
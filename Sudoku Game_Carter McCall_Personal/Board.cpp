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
#include "Alg.h"
#include "Colors.h"

/*
  Prints the board using for loops and the 2d
  array with numbers. Empty space and a special
  chars are used to make the board more organized
  and less cluttered.
*/

void Board::gameplayLoop() {
	Board bd;
	Alg alg;
	string input;
	int numInput, randNum;
	char repChar;
	bool loop = false;
	srand(time(0));
	randNum = rand() % 100;
	
	do
	{
		cout << "Would you like a predefined board (1), or a random board (2)? ";
		cin >> numInput;
		if (numInput == 1)
		{
			numInput == NULL;
			cout << "Would you like an easy board (1), or hard board (2)? ";
			cin >> numInput;
			if ((numInput == 1) && (randNum <= 50)) {
				for (int i = 0; i < 9; i++) {
					for (int j = 0; j < 9; j++) {
						nineByNine[i][j] = board1[i][j];
					}
				}
			}
			else if ((numInput == 1) && (randNum > 50)) {
				for (int i = 0; i < 9; i++) {
					for (int j = 0; j < 9; j++) {
						nineByNine[i][j] = board2[i][j];
					}
				}
			}
			else if ((numInput == 2) && (randNum <= 50)) {
				for (int i = 0; i < 9; i++) {
					for (int j = 0; j < 9; j++) {
						nineByNine[i][j] = board3[i][j];
					}
				}
			}
			else if ((numInput == 2) && (randNum > 50)) {
				for (int i = 0; i < 9; i++) {
					for (int j = 0; j < 9; j++) {
						nineByNine[i][j] = board4[i][j];
					}
				}
			}
		}
		else if (numInput == 2) {
			cout << "Would you like an easy board (1), or hard board (2)? ";
			cin >> numInput;
		}
		
		do
		{
			bd.printBoard(nineByNine);
			bd.coordinate();
			if (alg.check(nineByNine) == 2) loop = true;
			else loop = false;
			if (loop == false) system("cls");
		} while (loop);
		if (alg.check(nineByNine) == 1) cout << "INCORRECT! Would you like to try again? (Y|N): ";
		else cout << "CORRECT! Would you like to play again? (Y|N): ";
		do
		{
			cin >> input;
			repChar = tolower(input[0]);
		} while (repChar != 'y' && repChar != 'n');
	} while (repChar == 'y');
}

void Board::coordinate() {


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

void Board::printBoard(int a[9][9]) {

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
			if (a[i][j] == 0) cout << ' ';
			else cout << ANSI_COLOR_WHITE << a[i][j];
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

int Board::getNumber(int y, int x) {
	return nineByNine[y][x];
}
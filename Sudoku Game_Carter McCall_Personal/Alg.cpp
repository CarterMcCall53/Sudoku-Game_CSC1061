/*
*/

#include"Alg.h"

using namespace std;

void Alg::basicVectors() {
    for (int i = 0; i < 9; i++) {
        for (int j = 1; j < 10; j++) {
            row[i].push_back(j);
        }
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 1; j < 10; j++) {
            column[i].push_back(j);
        }
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 1; j < 10; j++) {
            square[i].push_back(j);
        }
    }
}

void Alg::randomBoard() {
    basicVectors();
    srand(time(0));
    bool squareTrue = false;
    bool columnTrue = false;
    int cube = 0;
    int columnNum = 0;
    int squareNum = 0;
    int whichC = 0;
    int which = 0;
    int randNum = 0;
    int size = 0;
        for (cube = 0; cube < 3; cube++) {
            for (int j = 0; j < 3;j++) {
                for (int i = 0; i < which*2; i++) cout << " ";
                for (int f = 0; f < 3; f++) {
                    squareTrue = false;
                    columnTrue = false;
                    while (!columnTrue || !squareTrue) {
                        randNum = rand() % row[j+which].size();
                        for (int i = 0; i < square[cube+which].size();) {
                            if (square[cube+which][i] == row[j+which][randNum]) {
                                squareTrue = true;
                                squareNum = i;
                                i = square[cube].size();
                            }
                            i++;
                            
                        }
                        for (int i = 0; i < column[f+which].size();i) {
                            if (column[f+which][i] == row[j + which][randNum]) {
                                columnTrue = true;
                                columnNum = i;
                                i = column[f+which].size();
                            }
                            i++;

                        }
                    }
                    board[j+which][f+which] = row[j+which][randNum];
                    row[j+which].erase(row[j+which].begin() + randNum);
                    column[f+which].erase(column[f+which].begin() + columnNum);
                    square[cube+which].erase(square[cube+which].begin() + squareNum);
                    cout << " " << board[j+which][f+which];
                }
                cout << endl;
            }

            
            which += 3;
        }
        which = 0;
        int rowNum = 0;
        columnNum = 0;
        int squ = 0;
        int sque = 0;
        bool add = false;
        bool addRow = false;
        bool addColumn = false;
        for (int i = 0; i < 3; i++) {
            for (int f = 0; f < 3; f++) {
                squ = f + (i * 3);
                if (square[squ].size() != 0) {
                        for (int j = 1; j < 10; j++) {
                            
                        }
                }
                whichC += 3;
            }
            which += 3;
        }
}

int Alg::getNumber(int x, int y) {
    return(board[x][y]);
}

int Alg::getRow(int square, int num) {
    int retVal = 0;
    if (0 <= square < 3) {

    }
    else if (3<= square < 6) {

    }
    return retVal;
}
int Alg::getColumn(int square, int num) {
    int retVal = 0;
    return retVal;
}


/*for (int i = 0; i < 9;i++) {
    for (int j = 0; j < 9;j++) {
        size = row[i].size();
        randNum = rand() % row[i].size();
        if (0 <= i && i < 3) cubecolumn = 0;
        else if (3 <= i && i < 6)  cubecolumn = 1;
        else if (6 <= i && i < 9) cubecolumn = 2;
        if (0 <= i && i < 3) cube = cubecolumn;
        else if (3 <= i && i < 6)  cube = cubecolumn + 3;
        else if (6 <= i && i < 9) cube = cubecolumn + 6;
        board[i][j] = row[i][randNum];
        cout << " " << board[i][j];
        for (int f = 0; f < column[i].size();f++) {
            if (row[i][randNum] == column[j][f]) {
                columnNum = f;
                break;
            }
        }
        for (int g = 0; g < square[i].size();g++) {
            if (row[i][randNum] == square[cube][g]) {
                cubeNum = g;
                break;
            }
        }
        row[i].erase(row[i].begin() + randNum);
        column[j].erase(column[j].begin() + columnNum);
        square[cube].erase(square[cube].begin() + cubeNum);

    }
    cout << endl;
}*/

/*for (int g = 0; g < 3; g++) {
                                for (int n = 0; n < 3; n++) {
                                    if (square[squ][j-1] != 0) {
                                        for (int h = 0; h < row[g + which].size(); h++) {
                                            if (square[squ][sque] == row[g + which][h]) {
                                                add = true;
                                                break;
                                            }
                                        }
                                        for (int h = 0; h < column[n + whichC].size(); h++) {
                                            if (square[squ][sque] == column[n + whichC][h]) {
                                                add = true;
                                                break;
                                            }
                                        }
                                        if (add) {

                                            board[g + which][n + whichC] = j;
                                            square[squ].erase(square[squ].begin() + sque);
                                            cout << " " << board[j + which][f + which];
                                        }
                                    }
                                }
                            }*/
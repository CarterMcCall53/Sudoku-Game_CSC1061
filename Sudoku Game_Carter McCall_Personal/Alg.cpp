/*
*/

#include"Alg.h"
#include "Board.h"

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
        int rowp = 0;
        int columnp = 0;
        bool add = false;
        bool addRow = false;
        bool addColumn = false;
        for (int i = 0; i < 3; i++) {
            for (int f = 0; f < 3; f++) {
                squ = f + (i * 3);
                if (square[squ].size() != 0) {
                        for (int j = 1; j < 10; j++) {
                            for (int g = 0; g < 3; g++) {
                                for (int r = 0; r < row[g + (i * 3)].size(); r++) {
                                    if (row[g + (i * 3)][r] == j) {
                                        addRow = true;
                                        rowNum = r;
                                    }
                                }
                                for (int h = 0; h < 3; h++) {
                                    
                                    for (int n = 0; n < column[h + (f * 3)].size(); n++) {
                                        if (column[h + (f * 3)][n] == j) {
                                            columnNum == n;
                                            addColumn = true;
                                        }
                                    }
                                    if (addRow && addColumn) {

                                        break;

                                    }

                                }
                                if (addRow && addColumn) {
                                    break;
                                }

                            }
                            if (addRow && addColumn) {
                                for (int g = 0; g < square[squ].size(); g++) {
                                    if (square[squ][g] == j) {
                                        sque = g;
                                        add = true;
                                    }
                                }
                            }
                            if (add) {
                                board[columnNum][rowNum] = row[columnNum][rowNum];
                                row[columnNum].erase(row[columnNum].begin() + rowNum);
                                column[rowNum].erase(column[rowNum].begin() + columnNum);
                                square[squ].erase(square[cube + which].begin() + sque);
                            }

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
    int modifier = 0;
    if (0 <= square < 3) {
        modifier = 0;
    }
    else if (3<= square < 6) {
        modifier = 3;
    }
    else if (6 <= square < 9) {
        modifier = 6;
    }

    if (0 <= num < 3) {
        retVal = 0 + modifier;
    }
    else if (3 <= num < 6) {
        retVal = 1 + modifier;
    }
    else if (6 <= num < 9) {
        retVal = 2 + modifier;
    }
    return retVal;
}
int Alg::getColumn(int square, int num) {
    int retVal = 0;
    int modifier = 0;
    
    return retVal;
}

int Alg::getSquare(int row, int column) {
    int retVal = 0;
    int cube = 0;
    if (0<= column && column < 3) {
        cube = 0;
    }
    else if (3 <= column && column < 6) {
        cube = 1;
    }
    else if (6 <= column && column < 9) {
        cube = 2;
    }

    if (0<= row && row < 3) {
        retVal = cube;
    }
    else if (3 <= row && row < 6) {
        retVal = cube + 3;
    }
    else if (6 <= row && row < 9) {
        retVal = cube + 6;
    }
    return retVal;
}

int Alg::check(int board[9][9]) {
    Board bd;
    for (int i = 0; i < 9; i++) {
        row[i].clear();
    }
    for (int i = 0; i < 9; i++) {
        column[i].clear();
    }for (int i = 0; i < 9; i++) {
        square[i].clear();
    }
    int retVal = 0;
    for (int i = 0; i < 9; i++) {
        for (int f = 0; f < 9; f++) {
            if (bd.getNumber(i,f) == 0) {
                retVal = 2;
                return retVal;
            }
        }
    }
    for (int i = 0; i < 9; i++) {
        int squ = 0;
        for (int f = 0; f < 9; f++) {
            squ = getSquare(i, f);
            row[i].push_back(bd.getNumber(i, f));
            column[f].push_back(bd.getNumber(i, f));
            square[squ].push_back(bd.getNumber(i, f));
        }
    }
    for (int i = 0; i < 9; i++) {
        sort(row[i].begin(), row[i].end());
        sort(column[i].begin(), column[i].end());
        sort(square[i].begin(), square[i].end());
    }
    for (int i = 0; i < 9; i++) {
        if (adjacent_find(row[i].begin(), row[i].end()) != row[i].end() || adjacent_find(column[i].begin(), column[i].end()) != column[i].end() || adjacent_find(square[i].begin(), square[i].end()) != square[i].end()) {
            retVal = 1;
            return retVal;
        }
    }
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
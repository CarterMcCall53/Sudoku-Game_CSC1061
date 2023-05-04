/*
*/

#include"Alg.h"

using namespace std;

#define DEBUG2

void Alg::randomBoard(int diffuculty) {
    //setting the seed of the randomization
    srand(time(0));
    int randNum = 0;
    //using vectors here to ensure that when the numbers are being shifted thay are in the correct place 
    vector<int> baseRow;
    for (int i = 0; i < 9; i++) {
        baseRow.push_back(i+1);
    }
    for (int i = 0; i < 9; i++) {
        //
        randNum = rand() % baseRow.size();
        rows[0].r.push_back(baseRow[randNum]);
        //cout << rows[0].r[i];
        baseRow.erase(baseRow.begin() + randNum);
    }
    for (int i = 1; i < 3; i++) {
        shift(i, 3);
    }
    shift(3, 1);
    for (int i = 4; i < 6; i++) {
        shift(i, 3);
    }
    shift(6, 1);
    for (int i = 7; i < 9; i++) {
        shift(i, 3);
    }
    
    
    randNum = 0;
    for (int i = 0; i < 3; i++) {
        for (int f = 0; f < 3; f++) {
            randNum = rand() % 3;
            rows[(i * 3) + randNum].r.swap(rows[f + (i * 3)].r);
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int f = 0; f < 3; f++) {
            randNum = rand() % 3;
            swapCol(randNum + (i * 3), f + (i * 3));
        }
    }
    for (int i = 0; i < 9; i++) {
        for (int f = 0; f < 9; f++) {
            board[i][f] = rows[i].r[f];
        }
    }
#ifdef DEBUG
    for (int i = 0; i < 9; i++) {
        for (int f = 0; f < 9; f++) {
            cout << board[i][f];
        }
        cout << endl;
    }

    int c = check(board);
    if (c == 0) {
        cout << "IT WORKS" << endl;
    }
#endif
    randNum = 0;
    int x = 0;
    int y = 0;
    int number = 0;
    if (diffuculty == 1) {
        randNum = rand() % 11;
        number = 30 + randNum;
    }
    if (diffuculty == 2) {
        randNum = rand() % 11;
        number = 20 + randNum;
    }
    for (int i = 0; i < 30; i++) {
        x = rand() % 9;
        y = rand() % 9;
        if (output[x][y] == 0) {
            output[x][y] = board[x][y];
        }
        else {
            i--;
            continue;
        }
    }
#ifdef DEBUG
    for (int i = 0; i < 9; i++) {
        for (int f = 0; f < 9; f++) {
            cout << output[i][f];
        }
        cout << endl;
    }
#endif
}

int Alg::getoutput(int x, int y) {
    return(output[x][y]);
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
    vector<int> row[9];
    vector<int> column[9];
    vector<int> square[9];
    int retVal = 0;
    for (int i = 0; i < 9; i++) {
        row[i].clear();
    }
    for (int i = 0; i < 9; i++) {
        column[i].clear();
    }
    for (int i = 0; i < 9; i++) {
        square[i].clear();
    }
    for (int i = 0; i < 9; i++) {
        for (int f = 0; f < 9; f++) {
            if (board[i][f] == 0) {
                retVal = 2;
                return retVal;
            }
        }
    }
    for (int i = 0; i < 9; i++) {
        int squ = 0;
        for (int f = 0; f < 9; f++) {
            squ = getSquare(i, f);
            row[i].push_back(board[i][f]);
            column[f].push_back(board[i][f]);
            square[squ].push_back(board[i][f]);
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

void Alg::shift(int ro, int move) {
    int temp = 0;
    for (int i = 0; i < 9; i++) {
        rows[ro].r.push_back(rows[ro - 1].r[i]);
    }
    for (int i = 0; i < move; i++) {
        temp = rows[ro].r[rows[ro].r.size()-1];
        rows[ro].r.insert(rows[ro].r.begin(), temp);
        rows[ro].r.pop_back();
    }
#ifdef DEBUG1
    for (int i = 0; i < rows[ro].r.size(); i++) {
        cout << rows[ro].r[i];
    }
#endif
}

void Alg::swapCol(int col, int newcol) {
    int value = 0;
    for (int i = 0; i < 9;i++) {
        value = rows[i].r[col];
        rows[i].r.erase(rows[i].r.begin() + col);
        rows[i].r.insert(rows[i].r.begin() + newcol, value);
    }
}
//storing outdated code for use if needed
///////////////////////////
// DELETE BEFORE TURN IN //
///////////////////////////
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
/*int squ = 0;
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
}*/
/*int Alg::getRow(int square, int num) {
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
}*/
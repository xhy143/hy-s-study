#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool is_valid(vector<vector<char>>& board, int row, int col, char num) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num) {
            return false;
        }
    }
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == num) {
            return false;
        }
    }
    int start_row = row - row % 3; 
    int start_col = col - col % 3; 
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[start_row + i][start_col + j] == num) {
                return false;
            }
        }
    }
    return true;
}


bool solve_sudoku(vector<vector<char>>& board) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == '.') {
                for (char num = '1'; num <= '9'; num++) {
                    if (is_valid(board, row, col, num)) {
                        board[row][col] = num;
                        if (solve_sudoku(board)) {
                            return true;
                        }
                        board[row][col] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<char> > board(9, vector<char>(9));
    
    for (int i = 0; i < 9; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < 9; j++) {
            board[i][j] = line[j];
        }
    }

    solve_sudoku(board);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j];
        }
        cout << endl;
    }
    
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, int c, vector<vector<int>>& board) {
    for (int i = 0; i < 9; i++) {
        
        // check column
        if (board[i][col] == c) return false;

        // check row
        if (board[row][i] == c) return false;

        // check 3x3 box
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
            return false;
    }
    return true;
}

bool solve(vector<vector<int>>& board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {

            if (board[i][j] == 0) { // empty cell

                for (int num = 1; num <= 9; num++) {
                    if (isSafe(i, j, num, board)) {

                        board[i][j] = num;

                        if (solve(board)) return true;

                        board[i][j] = 0; // backtrack
                    }
                }

                return false; // no valid number
            }
        }
    }
    return true; // solved
}

int main() {
    vector<vector<int>> board(9, vector<int>(9));

    // input
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }

    solve(board);

    // output
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
			if(j!=0) cout<<" ";
            cout << board[i][j];
        }
        cout << endl;
    }

    return 0;
}
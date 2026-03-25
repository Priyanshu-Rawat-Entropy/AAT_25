#include <iostream>
using namespace std;

int board[8][8];

bool isSafe(int row, int col) {

    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (int i = row, j = col; i < 8 && j >= 0; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solve(int col) {


    if (col >= 8)
        return true;

    for (int i = 0; i < 8; i++) {

        if (isSafe(i, col)) {

            board[i][col] = 1;

            if (solve(col + 1))
                return true;

            board[i][col] = 0;
        }
    }

    return false;
}

int main() {

    if (solve(0)) {
        cout << "One solution:\n";
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++)
                cout << (board[i][j] ? "Q" : ".") << " ";
            cout << endl;
        }
    } else {
        cout << "No solution exists." << endl;
    }

    return 0;
}
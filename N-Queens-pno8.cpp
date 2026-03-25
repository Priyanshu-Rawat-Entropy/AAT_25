#include <iostream>
using namespace std;

int board[10][10], N;


bool isSafe(int row, int col) {


    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;


    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;


    for (int i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j])
            return false;

    return true;
}


bool solve(int col) {


    if (col >= N)
        return true;

    for (int i = 0; i < N; i++) {

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
    cout << "Enter number of queens: ";
    cin >> N;

    if (solve(0)) {
        cout << "Solution:\n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                cout << (board[i][j] ? "Q" : ".") << " ";
            cout << endl;
        }
    } else {
        cout << "No solution exists." << endl;
    }

    return 0;
}
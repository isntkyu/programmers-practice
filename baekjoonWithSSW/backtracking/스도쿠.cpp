#include <iostream>

using namespace std;

int sd[9][9];

bool promising (int row, int col, int val) {
    for (int i = 0; i < 9; i++) {
        if (sd[i][col] == val)
            return false;
    }
    for (int i = 0; i < 9; i++) {
        if (sd[row][i] == val)
            return false;
    }

    row = (row / 3) * 3;
    col = (col / 3) * 3;
    for (int i = row; i < row + 3; i++) {
        for (int j = col; j < col + 3; j++) {
            if (sd[i][j] == val)
                return false;
        }
    }

    return true;
}

void backtracking(int row, int col) {
    if (col == 9) {
        backtracking(row + 1, 0);
        return;
    }

    if (row == 9) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if(i == 8 && j == 8) {
                cout << sd[i][j];
                exit(0);
            } else {
                cout << sd[i][j] << " ";
            }
        }
        cout << "\n";
    }
        return;
    }

    if (sd[row][col] == 0) {
        for (int i = 1; i <= 9; i++) {
            if (promising(row, col, i)) {
                sd[row][col] = i;
                backtracking(row, col + 1);
            }
        }
        sd[row][col] = 0;
        return;
    }

    backtracking(row, col + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> sd[i][j];
        }
    }
    backtracking(0, 0);
}
#include <iostream>

using namespace std;

int chess[15];
int answer = 0;
int n;

bool promising(int cidx) {
    for(int i = 0; i < cidx; i++) {
        if (chess[i] == chess[cidx] || cidx - i == abs(chess[cidx] - chess[i])) {
            return false;
        }
    }

    return true;
}

void nqueen (int cidx) {
    if (cidx == n) {
        answer++;
        return;
    }

    for (int i = 0; i < n; i++) {
        chess[cidx] = i;
        if (promising(cidx)) {
            nqueen(cidx + 1);
        }
    }
}

int main() {
    cin >> n;
    nqueen(0);
    cout << answer;
}
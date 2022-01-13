#include <iostream>
#include <algorithm>

using namespace std;

int Max = (1000000000 + 1) * -1;
int Min = -Max;
int n;
int number[12];
int cal[4];

void dfs(int p, int m, int x, int d, int cnt, int num) {
    if (cnt == n) {
        Max = max(Max, num);
        Min = min(Min, num);
    }

    if (p > 0)
        dfs(p - 1, m, x, d, cnt + 1, num + number[cnt]);
    if (m > 0)
        dfs(p, m - 1, x, d, cnt + 1, num - number[cnt]);
    if (x > 0)
        dfs(p, m, x - 1, d, cnt + 1, num * number[cnt]);
    if (d > 0)
        dfs(p, m, x, d - 1, cnt + 1, num / number[cnt]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> number[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> cal[i];
    }
    
    dfs(cal[0], cal[1], cal[2], cal[3], 1, number[0]);
    cout << Max << "\n" << Min;
}
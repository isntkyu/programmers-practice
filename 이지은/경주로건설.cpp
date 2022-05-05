#include <cstring>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

queue<tuple<int, int, int>> q;

int price[26][26];
bool visit[4][26][26];
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};

int solution(vector<vector<int>> board) {
    int endPoint = board.size() - 1;
    for (int i = 0; i < 26; i++) {
        memset(price[i], 0, sizeof(price[i]));
        for (int j = 0; j < 4; j++) memset(visit[j][i], false, sizeof(visit[j][i]));
    }
    
    q.push(make_tuple(0, 0, 0));
    visit[0][0][1] = true;
    visit[1][1][0] = true;
    
    while (!q.empty()) {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int z = get<2>(q.front());
        q.pop();
        
        
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i];
            int b = y + dy[i];
            
            if (board[a][b] != 1 && a > -1 && b > -1 && a <= endPoint && b <= endPoint) { 
                int cost = 100;
                if (z != i && !(a == 1 && b == 0)) { // && !(a == 1 && b == 0) && !(a == endPoint && b == endPoint)
                    cost += 500;
                }
                
                if (price[a][b] == 0 || (price[a][b] > price[x][y] + cost)) {
                    price[a][b] = price[x][y] + cost;
                    q.push(make_tuple(a, b, i));
                    // visit[i][a][b] = true;
                }
                
            }
            
        }
    }
    
    
    int answer = price[endPoint][endPoint];
    return answer;
}
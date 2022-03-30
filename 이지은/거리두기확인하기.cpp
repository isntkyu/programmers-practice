#include <string>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};
bool visit[5][5];
    
bool bfs(int a, int b, vector<string> v) {
    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < 5; i++) {
        memset(visit[i], false, sizeof(visit[i]));
    }
    q.push(make_pair(make_pair(a, b), 0));
    visit[a][b] = true;    
    
    while(!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int count = q.front().second;
        q.pop();
        if (count == 2) continue;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < 5 && ny < 5) {

                if (!visit[nx][ny]) {
                    if (v[nx][ny] == 'P') {
                        return false;
                    } else if (v[nx][ny] == 'O') {
                        visit[nx][ny] = true;
                        q.push(make_pair(make_pair(nx, ny), count + 1));
                    }
                }

            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> p) {
    vector<int> answer;
    
    
    for (int a = 0; a < 5; a++) {
  
        bool result = true;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (p[a][i][j] == 'P') {
                    if (!bfs(i, j, p[a])) {
                        answer.push_back(0);
                        result = false;
                        break;
                    }
                }
            }
            if (!result) break;
        }
        if (result)  answer.push_back(1);
    }
       
    return answer;
}
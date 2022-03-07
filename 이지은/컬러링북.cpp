#include <vector>
#include <queue>

using namespace std;

bool visit[100][100];
int tempMax, mx, ny;
queue<pair<int, int>> q;

void bfs(int a, int b, vector<vector<int>> v) {
    int color = v[a][b];
    q.push(make_pair(a, b));
    visit[a][b] = true;
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        if (x - 1 != -1 && !visit[x - 1][y] && v[x - 1][y] == color){
            tempMax++;
            q.push(make_pair(x - 1, y));
            visit[x - 1][y] = true;
        }
        if (x + 1 != mx && !visit[x + 1][y] && v[x + 1][y] == color){
            tempMax++;
            q.push(make_pair(x + 1, y));
            visit[x + 1][y] = true;
        }
        if (y + 1 != ny && !visit[x][y + 1] && v[x][y + 1] == color){
            tempMax++;
            q.push(make_pair(x, y + 1));
            visit[x][y + 1] = true;
        }
        if (y - 1 != -1 && !visit[x][y - 1] && v[x][y - 1] == color){
            tempMax++;
            q.push(make_pair(x, y - 1));
            visit[x][y - 1] = true;
        }
    }
    
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> p) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    mx = m;
    ny = n;
    
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            visit[i][j] = false;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visit[i][j] && p[i][j] != 0) {
                tempMax = 1;
                number_of_area++;
                bfs(i, j, p);
                max_size_of_one_area = max(max_size_of_one_area, tempMax);
                while( !q.empty() ) q.pop();
            }
        }
    }
    
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
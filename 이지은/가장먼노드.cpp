#include <cstring>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[20001];
int visit[20001] = {0,};
queue<int> q;

void bfs() {
    q.push(1);
    
    while(!q.empty()) {
        int from = q.front();
        q.pop();
        
        for (int i = 0; i < v[from].size(); i++) {
            if (visit[v[from][i]] == 0) {
                q.push(v[from][i]);
                visit[v[from][i]] = visit[from] + 1;
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    for (int i = 0; i < edge.size(); i++) {
        v[edge[i][0]].push_back(edge[i][1]);
        v[edge[i][1]].push_back(edge[i][0]);
    }
    
    bfs();
    
    int maxD = 0;
    for (int i = 2; i <= n; i++) {
        if (visit[i] > maxD) {
            answer = 1;
            maxD = visit[i];
        } else if (visit[i] == maxD) {
            answer++;
        }
    }
    
    return answer;
}
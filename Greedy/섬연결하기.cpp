#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

vector<int> graph[101];
bool check[101] = {false,};
bool b = false;
int to;

bool cmp(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}

void dfs (int start) {
    check[start] = true;
    for (int i = 0; i < graph[start].size(); i++) {
        if (to == graph[start][i]) {
            b = true;
            return;
        }
        if (!check[graph[start][i]]) dfs(graph[start][i]);
    }
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    sort(costs.begin(), costs.end(), cmp);
    
    for (int i = 0; i < costs.size(); i++) {
        int start = costs[i][0];
        to = costs[i][1];
        
        memset(check, false, sizeof(check));
        
        dfs(start);
        
        if (!b) {
            graph[start].push_back(to);
            graph[to].push_back(start);
            answer += costs[i][2];
        } else {
            b = false;
        }
    }
    
    return answer;
}
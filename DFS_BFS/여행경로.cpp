#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int cnt = 0;
void dfs(vector<vector<string>>& t, vector<string>& answer, vector<string>& temp, int use, string start, vector<bool>& visit) {
    temp.push_back(start);
    
    if (cnt < use) {
        cnt = use;
        answer = temp;
    }
    
    for (int i = 0; i < t.size(); i++) {
        if (start == t[i][0] && !visit[i]) {
            visit[i] = true;
            dfs(t, answer, temp, use + 1, t[i][1], visit);
            visit[i] = false;
        }
    }
    
    temp.pop_back();
}

vector<string> solution(vector<vector<string>> t) {
    vector<string> answer, temp;
    
    sort(t.begin(), t.end());
    
    vector<bool> visit(t.size(), false);
    dfs(t, answer, temp, 0, "ICN", visit);
    
    return answer;
}
#include <string>
#include <vector>
#include <cmath>


using namespace std;


bool visit[300001] = {0,};
vector<int> v[300001];
long long answer = 0;

void dfs(vector<long long> &a2, int parent){
    visit[parent] = true;
    
    for(int i = 0; i < v[parent].size();i++){
        if (!visit[v[parent][i]]) {
            dfs(a2, v[parent][i]);
            answer += abs(a2[v[parent][i]]);
            a2[parent] += a2[v[parent][i]];
        }
    }

}

long long solution(vector<int> a, vector<vector<int>> edges) {
    vector<long long> a2(a.begin(),a.end());
    
    int maxCheck = 0;
    for (int i = 0; i < a.size(); i++) 
        maxCheck += a[i];
    if (maxCheck != 0) return -1;
    
    for (int i = 0; i < edges.size(); i++) {
        v[edges[i][0]].push_back(edges[i][1]);
        v[edges[i][1]].push_back(edges[i][0]);
    }
    
    dfs(a2, 0);
    
    return answer;
}
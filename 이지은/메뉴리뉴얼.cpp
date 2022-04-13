#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<string, int> m;

void dfs (string s, string com, int idx, int n, int cnt) {
    if (com.length() == n) {
        m[com] = 0;
    }
    
    for (int i = idx; i < s.length(); i++) {
        com[cnt] = s[i];
        dfs(s, com, i + 1, n, cnt + 1);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for (int n: course) { // 모든 조합 map;
        for (string s: orders) {
            sort(s.begin(), s.end());
            string com = "";
            com.resize(n);
            dfs(s, com, 0, n, 0);
        }
    }
    
    
    for (auto val: m) {
        for (string s: orders) {
            bool b = true;
            for (int i = 0; i < val.first.length(); i++) {
                if (s.find(val.first[i]) == -1) {
                    b = false;
                    break;
                }
            }
            if (b) {
                m[val.first]++;
            }
        }
    }
    

    
    for(int n: course) {
        int max = 0;
        for (auto val: m) {
            if (val.first.length() == n && val.second > max) {
                max = val.second;
            }
        }
        
        for(auto val: m) {
            if (val.first.length() == n && val.second == max && max > 1) {
                answer.push_back(val.first);
            }
        }
    }
    

    sort(answer.begin(), answer.end());
    return answer;
}
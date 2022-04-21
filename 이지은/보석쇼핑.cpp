#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
set<string> str;

bool compare (string s) {
    set<string>::iterator iter;
    for (iter = str.begin(); iter != str.end(); iter++) {
        if (s.find(*iter) == -1) {
            return false;
        }
    }
    return true;
}

bool cmp (pair<int, int> a, pair<int, int> b) {
    if (a.second - a.first == b.second - b.first) {
        return a.first < b.first;
    }
    return a.second - a.first < b.second - b.first;
}

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    pair<int, int> min;
    min = make_pair(1, 1000001);
    for (int i = 0; i < gems.size(); i++) {
        str.insert(gems[i]);
    }
    unordered_map<string, int> um;
    
    int start = 0;
    int end = 0;
    while (true) {
        // string s = "";
        bool update = false;
        for (int i = end; i < gems.size(); i++) {
            // s = "";
            // for (int j = start; j <= i; j++) s += gems[j];
            um[gems[i]]++;
            if (um.size() == str.size()) {
                end = i;
                update = true;
                break;
            }
        }
        
        if (!update) break;
        
        
        for (int i = start; i < gems.size(); i++) {
            // s = s.substr(gems[i].length(), s.length() - gems[i].length());
            if (um[gems[i]] == 1) {
                start = i;
                break;
            } else {
                um[gems[i]]--;
            }
        }
        
        if (min.second - min.first > end - start) {
            min = make_pair(start + 1, end + 1);
        }
        
        um.erase(gems[start]);
        start++;
        end++;
    }
    
    answer.push_back(min.first);
    answer.push_back(min.second);
    return answer;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << solution({"AA", "AB", "AC", "AA", "AC"})[0];

    // cout << solution(10, 60, 45, {"23:59","23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59"});
}
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <map>

using namespace std;

map<int, int> m;

bool cmp (pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    string number = "";
    for (int i = 2; i < s.length() - 1; i++) {
        if (isdigit(s[i])) {
            number += s[i];
        }
        
        if ((s[i] == ',' || s[i] == '}') && isdigit(s[i - 1])) {
            m[stoi(number)]++;
            number = "";
        }
    }
    
    vector<pair<int, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);
    
    for (pair<int, int> i: v) {
        answer.push_back(i.first);
    }
    
    return answer;
}
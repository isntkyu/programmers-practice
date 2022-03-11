#include <string>
#include <vector>
using namespace std;


string upper(string s) {
    for (int i = 0; i < s.length(); i++) {
        s[i] = toupper(s[i]);
    }
    return s;
}

int solution(int s, vector<string> cities) {
    if (s == 0) return 5 * cities.size();
    
    
    int answer = 0;
    vector<string> v;
    
    for (int i = 0; i < cities.size(); i++) {
        bool hit = false;
        for (int j = 0; j < v.size(); j++) {
            if (upper(cities[i]) == v[j]) {
                answer++;
                hit = true;
                v.erase(v.begin() + j);
            }
        }
        if (!hit) {
            answer += 5;
            if (v.size() == s) {
                v.erase(v.begin());
            }
        }
        
        
        v.push_back(upper(cities[i]));
        
    }
    
    return answer;
}
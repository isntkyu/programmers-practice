#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> l, vector<int> r) {
    int answer = 0;
    
    for(int i = 0; i < l.size(); i++) {
        for(int j = 0; j < r.size(); j++){
            if (l[i] == r[j]) {
                r.erase(r.begin() + j);
                l.erase(l.begin() + i);
                j = 0;
                i = 0;
                break;
            }
        }
    }
    
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    
    for(int i = 0; i < l.size(); i++) {
        for(int j = 0; j < r.size(); j++){
            if ((l[i] - 1 == r[j]) || (l[i] + 1 == r[j])) {
                r.erase(r.begin() + j);
                j = 0;
                n++;
                break;
            }
        }
    }
    
    answer = (n - l.size()) > n ? n : n - l.size();
    return answer;
}
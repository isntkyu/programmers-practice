#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> p) {
    vector<int> answer;
    
    for (int i = 0; i < p.size() - 2; i++) {
        int count = 0;
        int std = p[i];
        
        for (int j = i + 1; j < p.size(); j++) {
            count++;
            if (std > p[j] || j == p.size() - 1) {
                answer.push_back(count);
                break;
            }
        }
    }
    
    answer.push_back(1);
    answer.push_back(0);
    
    return answer;
}
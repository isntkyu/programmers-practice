#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> t) {
    
    for (int i = 1; i < t.size(); i++) {
        for (int j = 0; j < t[i].size(); j++) {
            if (j == 0) {
                t[i][j] += t[i - 1][0];
            } else if (j == i) {
                t[i][j] += t[i - 1][j - 1];
            } else {
                if (t[i - 1][j - 1] > t[i - 1][j])
                    t[i][j] += t[i - 1][j - 1];
                else 
                    t[i][j] += t[i - 1][j];
            }
        }
    }
    
    int depth = t.size() - 1;
    int max = 0;
    for (int i = 0; i < t[depth].size(); i++) {
        if (t[depth][i] > max) {
            max = t[depth][i];
        }
    }
    
    return max;
}
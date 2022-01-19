#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b)
{
    return a[0] < b[0];
}

int solution(vector<vector<int> > r)
{
    int answer = 1;
    
    sort(r.begin(), r.end(), compare);
    
    int check = r[0][1];
    
    for(int i = 0; i < r.size(); i++) {
        if(check < r[i][0]) {
            answer++;
            check = r[i][1];
        }
        if(check >= r[i][1]) {
            check = r[i][1];
        }
    }
    
    return answer;
}
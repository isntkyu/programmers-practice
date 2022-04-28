#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

string toBinary(int n)
{
    string r;
    while (n != 0){
        r += ( n % 2 == 0 ? "0" : "1" );
        n /= 2;
    }
    return r;
}

// 최소성 확인
bool possi(vector<int> vec,int now){
    for(int i = 0; i < vec.size(); i++)
        // ans에 있던 조합이 이번에 들어온 조합이랑 같은 것인지 확인
        if((vec[i] & now) == vec[i])
            return false;

    return true;
}

int solution(vector<vector<string>> r) {
    vector<int> ans;
    
    int row = r.size();
    int col = r[0].size();
    
    for (int i = 0; i < (1 << col); i++) {
        set<string> s;
        
        for (int j = 0; j < row; j++) {
            string str = "";
            
            for (int k = 0; k < col; k++) {
                if (i & (1 << k)) {
                    str += r[j][k];
                }
            }
            
            s.insert(str);
        }
        
        if (s.size() == row && possi(ans, i)) {
            cout << toBinary(i) << " ";
            ans.push_back(i);
        }
    }
    
    return ans.size();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << solution({{"100","ryan","music","2"},{"200","apeach","math","2"},{"300","tube","computer","3"},{"400","con","computer","4"},{"500","muzi","music","3"},{"600","apeach","music","2"}});

    // cout << solution(10, 60, 45, {"23:59","23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59"});
}
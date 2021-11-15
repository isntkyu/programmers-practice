#include <iostream>
#include <stack>

using namespace std;

int nge[1000001] = {0,};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n ;
    stack<int> s;

    cin >> n;

    while(n--){
        int temp;
        cin >> temp;
        s.push(temp);
    }

    while(!s.empty()){
        for(int i = 0; i < s.size() - 1; i++){
            nge[i]
        }
    }
}
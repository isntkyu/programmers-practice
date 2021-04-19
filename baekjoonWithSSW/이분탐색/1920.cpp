#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unordered_map<string, bool> map;

    int n, m;

    cin >> n;

    for(int i = 0; i < n; i++){
        string temp;
        
        cin >> temp;

        map[temp] = true;
    }
    
    cin >> m;

    for(int i = 0; i < m; i++){
        string temp;

        cin >> temp;

        if(map[temp])
            cout << 1 << "\n";
        else
            cout << 0 << "\n";
    }
}
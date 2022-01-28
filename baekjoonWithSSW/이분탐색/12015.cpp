#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> v;
    v.push_back(0);

    int n;

    cin >> n;

    for(int i = 0; i < n; i++){
        int temp; 
        cin >> temp;
        
        if(temp > v.back()){
            v.push_back(temp);
        }else{
            v[lower_bound(v.begin(), v.end(), temp) - v.begin()] = temp;
        }
    }    

    cout << v.size() - 1 ;

}
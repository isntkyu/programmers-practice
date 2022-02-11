#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;




struct compare {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        if (a.second == b.second) return a.first > b.first;
        else return a.second > b.second;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if (temp == 0) {
            if (pq.empty()) {
                cout << 0 << "\n";
            } else {
                cout << pq.top().first << "\n";
                pq.pop();
            }
        } else {
            pq.push({temp, abs(temp)});
        }
    }
}
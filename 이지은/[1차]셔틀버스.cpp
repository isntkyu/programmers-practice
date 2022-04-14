#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    int ans = 0;
    vector<int> v;
    for (auto s: timetable) {
        v.push_back(stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2)));
    }
    sort(v.begin(), v.end());

    int bus = 540;
    int people = 0;
    int last = 0;
    for (int i = 0; i < n; i++) {
        // cout << "n " << n << endl;
        for (int j = 0; j < v.size(); j++) {
            int temp = v[j];
            if (temp <= bus && people < m) {
                people++;
                v[j] = 24 * 60 + 59;
                last = temp;
                // cout << temp <<endl;
            }
        }
        if (i == (n - 1)) { //막차
            if (people == m) {
                ans = last - 1;
            } else {
                ans = bus;
            }
        }
        bus += t;
        people = 0;
    }

    int h = ans / 60;
    if (h < 10) {
        answer += '0' + to_string(h) + ':';
    } else {
        answer += to_string(h) + ':';
    }

    int minutes = ans % 60;
    if (minutes < 10) {
        answer += '0' + to_string(minutes);
    } else {
        answer += to_string(minutes);
    }


    // cout << ans << "  " ;
    return answer;
} 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << solution(2, 1, 2, {"09:00", "09:00", "09:00", "09:00"});

    // cout << solution(10, 60, 45, {"23:59","23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59"});
}
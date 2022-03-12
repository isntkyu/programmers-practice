#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int coin[6] = {1, 5, 10, 50, 100, 500};

bool compare(tuple<int, int, double> a, tuple<int, int, double> b) {
    if (get<2>(a) == get<2>(b)) return get<0>(a) > get<0>(b);
    return get<2>(a) < get<2>(b);
}

int solution(int money, vector<int> costs) {
    int answer = 0;

    vector<tuple<int, int, double>> v;
    for (int i = 0; i < costs.size(); i++) {
        v.push_back(make_tuple(coin[i], costs[i], (costs[i] / (double)coin[i])));
    }

    sort(v.begin(), v.end(), compare);

    // for (int i= 0; i < v.size(); i++)
    //     cout << get<0>(v[i]) << " "<< get<1>(v[i]) << " "<< get<2>(v[i]) << endl;

    for (int i = 0; i < v.size(); i++) {
        answer += (money / get<0>(v[i])) * get<1>(v[i]);
        // cout << (money / get<0>(v[i])) * get<1>(v[i]) << endl;
        money %= get<0>(v[i]);
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << solution(1999, {2, 11, 20, 100, 200, 600} );
}
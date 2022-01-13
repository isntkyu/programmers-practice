#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k, n;
    int ans = 0;
    vector<long long> v;

    cin >> k >> n;

    for (int i = 0; i < k; i++)
    {
        ll temp;
        cin >> temp;
        v.push_back(temp);
    }

    ll start = 1;
    ll end = *max_element(v.begin(), v.end());

    while (start <= end)
    {
        ll mid = (start + end) / 2;

        int cnt = 0;
        for (int i = 0; i < v.size(); i++)
        {
            cnt += v[i] / mid;
        }

        if (cnt >= n)
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    cout << ans;
}
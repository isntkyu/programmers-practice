#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n, m;
    vector<long long> v;

    cin >> n >> m;

    for (long long i = 0; i < n; i++)
    {
        long long temp;
        cin >> temp;
        v.push_back(temp);
    }

    long long start = 0;
    long long end = *max_element(v.begin(), v.end());
    long long answer = 0;
    while (start <= end)
    {
        long long mid = (start + end) / 2;
        long long meter = 0;

        for (long long i = 0; i < v.size(); i++)
        {
            meter += v[i] - mid >= 0 ? v[i] - mid : 0;
        }

        if (meter >= m)
        {
            answer = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    cout << answer;
}
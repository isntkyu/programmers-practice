#include <iostream>

using namespace std;

pair<int, int> arr[41];

void pivo(int n)
{
    if (n == 0)
    {
        arr[n].first = 1;
        return;
    }
    else if (n == 1)
    {
        arr[n].second = 1;
        return;
    }
    else
    {
        if (arr[n - 2].first == 0 || arr[n - 2].second == 0)
            pivo(n - 2);
        if (arr[n - 1].first == 0 || arr[n - 1].second == 0)
            pivo(n - 1);

        arr[n].first = arr[n - 2].first + arr[n - 1].first;
        arr[n].second = arr[n - 2].second + arr[n - 1].second;

        return;
    }
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, t;

    cin >> t;

    while (t--)
    {
        cin >> n;

        pivo(n);

        cout << arr[n].first << " " << arr[n].second << "\n";
    }
}
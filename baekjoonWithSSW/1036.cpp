#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int to10(char c)
{
    int n;

    if (c <= 9 && c >= 0)
    {
        n = (int)c;
    }
    else
    {
        n = c - '7';
    }

    return n;
}

char to36(int n)
{
    char c;

    if (n >= 0 && n <= 9)
    {
        c = (char)n;
    }
    else
    {
        c = (char)(n + '7');
    }

    return c;
}

int main()
{
    int n;
    vector<string> v;
    string answer = "";
    int arr[36] = {
        0,
    };

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }

    int k;

    cin >> k;

    int sum = 0;

    for (int i = 0; i < v.size(); i++)
    {
        int z = 1;

        for (int j = v[i].length() - 1; j >= 0; j--)
        {
            arr[to10(v[i][j])] += z;
            sum += (to10(v[i][j]) * z);

            z *= 36;
        }
    }

    priority_queue<pair<int, int> > pq;

    for (int i = 0; i < 36; i++)
    {
        if (arr[i] != 0)
            pq.push(make_pair(arr[i], i));
    }

    for (int i = 0; i < k; i++)
    {
        sum += (pq.top().first * (35 - pq.top().second));
        //cout << to36(pq.top().second) << "\n";
        pq.pop();
    }

    //cout << sum;
}
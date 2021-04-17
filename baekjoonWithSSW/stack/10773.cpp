#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int n;
    stack<int> s;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;

        if (temp == 0)
            s.pop();
        else
            s.push(temp);
    }

    int ans = 0;
    while (!s.empty())
    {
        ans += s.top();
        s.pop();
    }

    cout << ans;
}
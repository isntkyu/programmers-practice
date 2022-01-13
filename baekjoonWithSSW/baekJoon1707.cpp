#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> v[20001];
int color;
int check[20001];

bool bfs(int start)
{
    queue<int> q;
    color = 1;
    q.push(start);
    check[start] = color;

    while (!q.empty())
    {
        int temp = q.front();
        q.pop();

        for (int i = 0; i < v[temp].size(); i++)
        {
            if (check[v[temp][i]] == 0)
            {
                q.push(v[temp][i]);
                check[v[temp][i]] = check[temp] * (-1);
            }
            else if (check[v[temp][i]] == check[temp])
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int k;

    cin >> k;

    for (int i = 0; i < k; i++)
    {
        memset(check, 0, sizeof(check));
        int node, edge;

        cin >> node >> edge;

        for (int j = 0; j < edge; j++)
        {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }

        bool b = true;
        for (int j = 1; j <= node; j++)
        {
            if (check[j] == 0)
                if (!bfs(j))
                {
                    cout << "NO\n";
                    b = false;
                    break;
                }
        }

        if (b)
            cout << "YES\n";

        for (int j = 0; j <= node; j++)
        {
            v[j].clear();
        }
    }
}
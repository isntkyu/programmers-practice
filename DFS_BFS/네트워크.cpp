#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;

    queue<int> q;
    bool check[200] = {
        false,
    };

    for (int a = 0; a < n; a++)
        for (int b = 0; b < n; b++)
        {
            if (computers[a][b] == 1 && !check[a])
            {
                q.push(a);
                check[a] = true;

                while (!q.empty())
                {
                    int temp = q.front();

                    q.pop();

                    for (int i = 0; i < computers.size(); i++)
                    {
                        if (i != temp && computers[i][temp] == 1 && !check[i])
                        {
                            check[i] = true;
                            q.push(i);
                        }
                    }
                }

                answer++;
            }
        }

    return answer;
}
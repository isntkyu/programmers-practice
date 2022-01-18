#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> o)
{
    vector<int> answer;

    vector<int> pq;

    for (int i = 0; i < o.size(); i++)
    {
        if (o[i][0] == 'I')
        {
            pq.push_back(stoi(o[i].substr(2)));
        }
        else
        {
            if (pq.empty())
            {
                continue;
            }
            else if (o[i][2] == '-')
            {
                sort(pq.begin(), pq.end(), greater<int>());
                pq.pop_back();
            }
            else
            {
                sort(pq.begin(), pq.end());
                pq.pop_back();
            }
        }
    }

    if (pq.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        sort(pq.begin(), pq.end());
        answer.push_back(pq[pq.size() - 1]);
        answer.push_back(pq[0]);
    }
    return answer;
}
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<string, int> a, pair<string, int> b)
{
    return a.second > b.second;
}

bool compare2(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
        return a.first < b.first;

    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;

    unordered_map<string, int> m;
    unordered_map<string, vector<pair<int, int>>> u;

    for (int i = 0; i < genres.size(); i++)
    {
        m[genres[i]] += plays[i];
        u[genres[i]].push_back(make_pair(i, plays[i]));
    }

    vector<pair<string, int>> com(m.begin(), m.end()); //m.sort
    sort(com.begin(), com.end(), compare);

    unordered_map<string, vector<pair<int, int>>>::iterator it;
    for (it = u.begin(); it != u.end(); it++)
    {
        sort(it->second.begin(), it->second.end(), compare2);
    }

    for (int i = 0; i < com.size(); i++)
    {
        if (u[com[i].first].size() == 1)
        {
            answer.push_back(u[com[i].first][0].first);
            continue;
        }
        for (int j = 0; j < 2; j++)
        {
            answer.push_back(u[com[i].first][j].first);
        }
    }

    return answer;
}
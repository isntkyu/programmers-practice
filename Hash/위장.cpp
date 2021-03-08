#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes)
{
    int answer = 0;
    unordered_map<string, vector<string>> m;

    for (int i = 0; i < clothes.size(); i++)
    {
        m[clothes[i][1]].push_back(clothes[i][0]);
    }

    int a = 1;

    for (pair<string, vector<string>> i : m)
    {
        a *= (i.second.size() + 1);
    }
 
    return answer + a - 1;
}
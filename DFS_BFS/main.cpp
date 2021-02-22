#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int answer = 0;

void dfs(int target, vector<int> numbers, vector<int> s, int depth)
{
    if (depth == numbers.size())
    {
        int sum = 0;
        for (auto i : s)
        {
            sum += i;
        }

        if (target == sum)
        {
            answer++;
        }

        return;
    }

    s.push_back(numbers[depth]);
    dfs(target, numbers, s, depth + 1);
    s.pop_back();

    s.push_back(numbers[depth] * -1);
    dfs(target, numbers, s, depth + 1);
    s.pop_back();
}

int solution(vector<int> numbers, int target)
{

    vector<int> s;
    dfs(target, numbers, s, 0);

    return answer;
}

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    int target = 3;

    cout << solution(v, target);
}
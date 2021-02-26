#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
    string sa = to_string(a);
    string sb = to_string(b);

    return (sa + sb) > (sb + sa);
}

string solution(vector<int> numbers)
{
    string answer = "";

    sort(numbers.begin(), numbers.end(), compare);

    if (numbers.front() == 0)
        return to_string(0);

    for (int i = 0; i < numbers.size(); i++)
    {
        answer += to_string(numbers[i]);
    }

    return answer;
}
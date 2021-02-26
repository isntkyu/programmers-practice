#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> c)
{
    int a;
    sort(c.begin(), c.end(), greater<int>());

    for (a = 0; a < c.size(); a++)
    {
        if (c[a] <= a)
            break;
    }

    return a;
}
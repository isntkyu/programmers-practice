#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool prime(int a)
{

    for (int i = 2; i * i <= a; i++)
    {
        if ((a % i) == 0)
            return false;
    }

    return true;
}

int solution(string numbers)
{
    int answer = 0;

    sort(numbers.begin(), numbers.end(), greater<>());

    for (int i = 2; i <= stoi(numbers); i++)
    {
        if (prime(i))
        {
            string n = numbers;
            bool b = 1;
            string str = to_string(i);

            for (int j = 0; j < str.length(); j++)
            {
                if (n.find(str[j]) != string::npos)
                {
                    n[n.find(str[j])] = '*';
                }
                else if (n.find(str[j]) == string::npos)
                {
                    b = 0;
                    break;
                }
            }

            if (b)
                answer++;
        }
    }

    return answer;
}
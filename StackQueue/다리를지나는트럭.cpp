#include <string>
#include <queue>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    queue<int> q;
    vector<int> done;
    int size = 0;
    int answer = 0;
    int i = 0;
    while (1)
    {
        answer++;

        if (q.size() == bridge_length)
        {
            done.push_back(q.front());
            size -= q.front();
            q.pop();
        }

        if (weight >= (size + truck_weights[i]))
        {

            if (i == (truck_weights.size() - 1))
            {
                answer += bridge_length;
                break;
            }

            size += truck_weights[i];
            q.push(truck_weights[i]);
            i++;
        }
        else
            q.push(0);
    }

    return answer;
}

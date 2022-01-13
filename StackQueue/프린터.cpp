#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(vector<int> p, int loca)
{
    int answer = 0;
    deque<pair<int, int> > q;

    for (int i = 0; i < p.size(); i++)
    {
        q.push_back(make_pair(p[i], i));
    }

    while (1)
    {   
        bool b = false;
        for (int i = 1; i < q.size(); i++) {
            if(q[i].first > q.front().first) {
                b = !b;
                break;
            }
        }
        
        if(b) {
            q.push_back(q.front());
            q.pop_front();
        } else {
            answer++;
            if (q.front().second == loca) {
                break;
            }
            q.pop_front();
        }
        
    }

    return answer;
}
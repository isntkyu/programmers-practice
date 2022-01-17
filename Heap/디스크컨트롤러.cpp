#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct s{
  int i;
  int c;
  
  s(int num, int alpha) : i(num), c(alpha) {}
};

struct cmp {
  bool operator()(s a, s b) {
    return a.c > b.c;
  }
};

bool compare(vector<int> v1, vector<int> v2) {
    return v1[0] > v2[0];
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int size = jobs.size();

    sort(jobs.begin(), jobs.end(), compare);
    priority_queue <s, vector<s>, cmp> pq;



    pq.push(s(jobs[size - 1][0], jobs[size - 1][1]));
    jobs.pop_back();
    int time = pq.top().i;

    while(!pq.empty()) {
        time += pq.top().c;
        // cout << "time : " << time << endl;
        answer += time - pq.top().i;
        
        pq.pop();

        for (int i = jobs.size() - 1; i >= 0; i--) {
            if (jobs[i][0] <= time) {
                pq.push(s(jobs[i][0], jobs[i][1]));
                jobs.pop_back();
                cout << "!";
            }
        }

        if (!jobs.empty() && pq.empty()) {
            pq.push(s(jobs[jobs.size() - 1][0], jobs[jobs.size() - 1][1]));
            time = pq.top().i;
            jobs.pop_back();
        }

        // cout << "answer : " << answer << endl;
    }


    return answer / size;
}

int main(){
    // cout << solution({{0,3},{4,6},{5,3}, {4, 1}});
    cout << solution({{0,3}, {10, 4}});
}


// 요청시간으로 정렬하고 하나씩 pop 하면서 일 진행
// 그 일 끝나면 실행가능한 일들 요청시간이 진행중인시간보다 짧은애들 준비
// 준비상태인애들은 소요시간 정렬
// 일 진행중일때마다 준비상태큐에 추가
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {

    long long answer = 0;

    priority_queue<int> pq;

    for(int i = 0; i < works.size(); i++){
        pq.push(works[i]);
    }

    while(n--){
        if(pq.top() > 0){

            pq.push(pq.top() - 1);
            pq.pop();

        }
    }

    while(!pq.empty()){
        answer += pq.top() * pq.top();
        pq.pop();
    }
    
    return answer;
}
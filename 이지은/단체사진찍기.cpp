#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check(string str, char f, char s, char d, int dist) {
    int a = str.find(f) - str.find(s);
    int distance = abs(a) - 1;
    
    if (d == '=') {
        return distance == dist;
    }
    else if (d == '>') {
        return distance > dist;
    }
    else {
        return distance < dist;
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    string str = "ACFJMNRT";
    
    do {
        bool flag = true;
        for (string s : data) {
            char first = s[0];
            char second = s[2];
            char diff = s[3];
            int dist = s[4] - '0';
            
            if (!check(str, first, second, diff, dist)) {
                flag = false;
                break;
            }
        }
        if (flag) answer++;
    } while (next_permutation(str.begin(), str.end()));
    
    return answer;
}
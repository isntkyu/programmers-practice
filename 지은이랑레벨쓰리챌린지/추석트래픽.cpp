#include <string>
#include <vector>

using namespace std;


/*
각 로그별로 시작할때 1초 안으로 시작하거나 끝나는 로그 개수  x
각 로그별로 종료될때 1초 안으로 시작하거나 끝나는 로그 개수  x

오름차순이라서 현재 로그보다 뒤의 로그들이
현재로그의 끝점 + 1보다만 이전에 시작했으면 무조건 같이 카운팅될수잇다.
*/


int solution(vector<string> lines) {
    int answer = 0;
    vector<pair<double, double>> v;
    
    for (int i = 0; i < lines.size(); i++) {
        string s = lines[i].substr(11,12);
        double endTime = (stod(s.substr(0,2)) * 3600) + (stod(s.substr(3,2)) * 60) + stod(s.substr(6,2)) + (stod(s.substr(9)) / 1000.0);

        string e = lines[i].substr(24);
        double startTime = endTime - stod(e.substr(0, e.length()-1)) + 0.001;
        
        v.push_back(make_pair(startTime, endTime));
    }
    
    for (int i = 0; i < lines.size(); i++) {
        int count = 1;
        double end = v[i].second + 1;
        for (int j = i + 1; j < lines.size(); j++) {
            if (v[j].first < end)
                count++;
        }
        answer = max(answer, count);
    }
                    
    // for (int i = lines.size() - 1; i >= 0; i--) {
    //     int count = 0;
    //     double start = v[i].second - 1;
    //     double end = v[i].second;
    //     for (int j = lines.size() - 1; j >= 0; j--) {
    //         if ((start <= v[j].first && end >= v[j].first) || (start <= v[j].second && end >= v[j].second))
    //             count++;
    //     }
    //     answer = max(answer, count);
    // }
                    
    
    return answer;
}
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> s, int k) {
    int answer = 0;
    
    int min = 1;
    int max = 200000001;
    while (min <= max) {
        int zeroCount = 0;
        int mid = (min + max) / 2;
        bool pos = true;
        
        for (int i = 0 ; i < s.size(); i++) {
            if (s[i] < mid) {
                zeroCount++;
            } else {
                zeroCount = 0;
                continue;
            }
            
            if (zeroCount == k) {
                pos = false;
                break;
            }
        }
        
        if (pos) {
            answer = mid;
            min = mid + 1;
        } else {
            max = mid - 1;
        }
        
    }
    
    
    // 정확성만 통과하는코드
//     while (true) {
        
//         int zeroCount = 0;
//         for (int i = 0; i < s.size(); i++) {
            
//             if (s[i] == 0) {
//                 zeroCount++;
//             } else {
//                 s[i]--;
//                 zeroCount = 0;
//                 continue;
//             }
            
//             if (zeroCount == k) {
//                 return answer;
//             }
           
//         }
        
//         answer++;
//     }
    
    return answer;
}

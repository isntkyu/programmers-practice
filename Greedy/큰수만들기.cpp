#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    vector<int> v;
    
    int n = number.length() - k;
    int max = 0, maxindex = 0, index = 0;
    
    for(int j = 0; j < n ; j++){
    
    for(int i = index; i <= k + j; i++){
        if((int)number[i] > max){
            max = (int)number[i];
            maxindex = i;
        }
    }
    index= maxindex + 1;
    answer += (char)max;
    max = 0;
        
    }
    
    
    
    
    return answer;
}
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> p, vector<int> s) {
    vector<int> answer;
    int index = 0;
    int count = 0;
    
    while(1){
    
        for(int i = 0; i < p.size(); i++){
            p[i] += s[i];
        }
        
        while(1){
            if(p[index] >= 100){
                
                
                if(index >= p.size() - 1){
                    answer.push_back(count + 1);
                    break;
                }
                count++;
                index++;
               
            }          
            else{
                if(count != 0){
                    answer.push_back(count);
                    count = 0;
                }                    
                break;
            }
        }
        
        if(index == p.size() - 1 && p[index] >= 100)
            break;
    }
    
    return answer;
}
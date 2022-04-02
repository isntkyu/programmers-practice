#include <string>
#include <stack>
#include <vector>

using namespace std;
string answer = "";

bool correct(string str) {
    stack<char> s;
    if (str[0] == ')') return false;
    else s.push(str[0]);
    
    for (int i = 1; i < str.length(); i++) {
        if (s.top() != str[i]) s.pop();
        else s.push(str[i]);
    }
    
    if (s.empty()) return true;
    else return false;
}

void transform (string s) {
    if (s == "") return;
    
    int lC = 0;
    int rC = 0;
    if (s[0] == '(') lC++;
    else rC++;
    
    int i = 0;
    string u = "";
    u += s[i];
    i++;
    
    while (lC != rC) {
        if (s[i] == '(') lC++;
        else rC++;
        u += s[i];
        i++;
    }
    
    string v = s.substr(i, s.length() - 1);
    
    if (correct(u)) {
        answer += u;
        transform(v);
    }
    else {
        answer += '(';
        transform(v);
        answer += ')';
        for (int j = 1; j < u.length() - 1; j++) {
            if (u[j] == '(') answer += ')';
            else answer += '(';
        }
    }
}

string solution(string p) {
    transform(p);
    
    return answer;
}
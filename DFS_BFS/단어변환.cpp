#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<string> v;
string b, t;
int dep[50] = {0,};
bool visit[50] = {0,};

bool compare(string a, string b) {
    int count = 0;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] != b[i]) {
            count++;
        }
    }
    if (count == 1) return true;
    else return false;
}

void dfs(int n, string s, int index) {
    n++;
    
    if (t == s) {
        if (dep[index] == 0) {
            dep[index] = n;
        } else {
            dep[index] = dep[index] > n ? n : dep[index];
        }
        return;
    } else {
        visit[index] = true;
    }
    
    for (int i = 0; i < v.size(); i++) {
        if (compare(v[i], s) && !visit[i]) {
            
            dfs(n, v[i], i);
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    v = words;
    b = begin;
    t = target;
    
    int ansIndex = 51;
    for (int i = 0; i < words.size(); i++) {
        if (words[i] == t) {
            ansIndex = i;
            break;
        }
    }
    
    if (ansIndex == 51) return 0;
    
    for (int i = 0; i < words.size(); i++) {
        if (compare(begin, words[i])) {
            dfs(answer, words[i], i);
            memset(visit, false, sizeof(visit));
        }
    }
    
    return dep[ansIndex];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // "hit"	"cog"	["hot", "dot", "dog", "lot", "log", "cog"]
    vector<string> vec;
    vec.push_back("hot");
    vec.push_back("dot");
    vec.push_back("dog");
    vec.push_back("lot");
    vec.push_back("log");
    vec.push_back("cog");
    cout << solution("hit", "cog", vec);
}
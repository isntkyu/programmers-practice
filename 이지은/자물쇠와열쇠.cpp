#include <string>
#include <vector>

using namespace std;

void rotation (vector<vector<int>> &key) {
    vector<vector<int>> temp(key.size(), vector<int>(key.size()));

    for (int i = key.size() - 1; i >= 0; i--) {
        for (int j = 0; j < key.size(); j++) {
            temp[j][i] = key[key.size() - i - 1][j];
        }
    }
    
    key = temp;
}

bool match(int x, int y, vector<vector<int>> key, vector<vector<int>> map){
    for (int i = x; i < x + key.size(); i++) {
        for (int j = y; j < y + key.size(); j++) {
            map[i][j] += key[i - x][j - y];
        }
    }
    
    for (int i = key.size() - 1; i <= map.size() - key.size(); i++) {
        for (int j = key.size() - 1; j <= map.size() - key.size(); j++) {
            if (map[i][j] == 1) continue;
            return false;
        }
    }
    
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    
    int mapSize = lock.size() + (key.size() - 1) * 2;
    vector<vector<int>> map(mapSize, vector<int>(mapSize, 0));
    
    for (int i = key.size() - 1; i <= mapSize - key.size(); i++) {
        for (int j = key.size() - 1; j <= mapSize - key.size(); j++) {
            map[i][j] = lock[i - key.size() +1][j - key.size() + 1];
        }
    }
    
    for (int a = 0; a < 4; a++) {
        
        for (int i = 0; i <= mapSize - key.size(); i++) {
            for (int j = 0; j <= mapSize - key.size(); j++) {
                if (match(i, j, key, map)) {
                    answer = true;
                    return answer;
                }
            }
        }
        
        rotation(key);
    }
    
    return answer;
}
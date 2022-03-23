#include <string>
#include <vector>
#include <algorithm>

using namespace std;
 // 0, 2, 3, 1
 // 위, 아래, 오른, 왼
vector<string> v;
bool visit[500][500][4];

int cycle (int x, int y, int z, int len) {
    if (visit[x][y][z]) return len;
    
    visit[x][y][z] = true;
    int nextX, nextY, nextZ;
    
    if (v[x][y] == 'S') {
        nextZ = z;
    } else if (v[x][y] == 'L') {
        nextZ = (z + 1) % 4;
    } else {
        nextZ = z - 1;
        if (nextZ == -1) nextZ = 3;
    }
    
    if (nextZ == 0){
        nextX = x + 1;
        if (nextX == v.size()) nextX = 0;
        nextY = y;
    } else if (nextZ == 1){
        nextY = y + 1;
        if (nextY == v[0].length()) nextY = 0;
        nextX = x;
    } else if (nextZ == 2) {
        nextX = x - 1;
        if (nextX == -1) nextX = v.size() - 1;
        nextY = y;
    } else if (nextZ == 3) {
        nextY = y - 1;
        if (nextY == -1) nextY = v[0].length() - 1;
        nextX = x;
    }
    
    
    return cycle(nextX, nextY, nextZ, len + 1);
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    v = grid;
    
    for (int i = 0; i < 500; i++) {
        for (int j = 0; j < 500; j++) {
            for (int k = 0; k < 4; k++) {
                visit[i][j][k] = false;
            }
        }
    }
    
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].length(); j++) {
            for (int k = 0; k < 4; k++) {
                if (!visit[i][j][k]) {
                    int result = cycle(i, j, k, 0);
                    if (result != 0) answer.push_back(result);
                }
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}
n,m = map(int, input().split())

map = list()

for i in range(n):
    map.append(input())

list1 = [['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
 ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
 ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
 ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
 ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
 ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
 ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
 ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W']]

list2 =[['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
 ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
 ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
 ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
 ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
 ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
 ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
 ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B']]

arr = []

for i in range(n - 7):
    for j in range(m - 7):
        countB = 0
        countW = 0
        x = 0
        for a in range(i, i + 8):
            y = 0
            for b in range(j, j + 8):
                if map[a][b] != list1[x][y] :
                    countB = countB + 1
                if map[a][b] != list2[x][y] :
                    countW = countW + 1
                y = y + 1
            x = x + 1
        arr.append(countB)
        arr.append(countW)

print(min(arr))



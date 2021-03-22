
n = int(input())
list1 = list(map(int, input().split()))
list2 = list(map(int, input().split()))

ans = list1[0] * list2[0]

m = list2[0]
d = 0
for i in range(1, n - 1):
    if list2[i] < m:
        ans += m * d
        d = list1[i]
        m = list2[i]
    else:
        d += list1[i]
    if i == n - 2:
        ans += m * d

print(ans)
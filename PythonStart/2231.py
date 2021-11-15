n = int(input())

ans = 0

for i in range(1, n + 1):
    a = list(map(int, str(i)))
    ans = sum(a) + i
    if ans == n:
        print(i)
        break
    if i == n:
        print(0)

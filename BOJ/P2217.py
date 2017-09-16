N = int(input())
ropes = []

for _ in range(N):
    ropes.append(int(input()))

ropes.sort()

ret = -1

for rope, count in zip(ropes, range(N, 0, -1)):
    ret = max(ret, rope * count)

print(ret)

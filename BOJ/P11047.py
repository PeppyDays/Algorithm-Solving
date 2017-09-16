from sys import stdin


n, k = (int(x) for x in stdin.readline().split())
coins = []

for _ in range(n):
    coins.append(int(stdin.readline().strip()))

coins.reverse()

ret = 0

for coin in coins:
    ret += int(k / coin)
    k = k % coin

print(ret)

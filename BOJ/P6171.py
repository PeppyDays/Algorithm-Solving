import sys

sys.setrecursionlimit(100000)

N = int(input())
RE = []
Cache = [None] * N

for _ in range(N):
    RE.append([int(_) for _ in input().split()])


def find(here: int) -> int:
    if here > N - 1:
        return 0

    if here == N - 1:
        return RE[here][0] * RE[here][1]

    if Cache[here] is not None:
        return Cache[here]

    this_height = 0
    this_width = 0
    min_price = float('inf')

    for there, re in enumerate(RE[here:], start=here):
        this_height = max(this_height, re[0])
        this_width = max(this_width, re[1])
        min_price = min(min_price, this_height * this_width + find(there + 1))

    Cache[here] = min_price
    return min_price


print(find(0))

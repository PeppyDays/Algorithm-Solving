from collections import defaultdict
import sys


inf = sys.maxsize


def bellman_ford():
    global V, adj, reachable, upper

    upper[0] = 0

    for _ in range(V - 1):
        for here in range(V):
            for there, dists_here_to_there in adj.get(here, {}).items():
                for dist_here_to_there in dists_here_to_there:
                    upper[there] = min(upper[there], upper[here] + dist_here_to_there)

    for here in range(V):
        for there, dists_here_to_there in adj.get(here, {}).items():
            for dist_here_to_there in dists_here_to_there:
                if upper[here] + dist_here_to_there < upper[there]:
                    if reachable[0][here] and reachable[here][1]:
                        return -inf

    return upper[1]


T = int(input())

for t in range(T):
    V, E = [int(x) for x in input().split()]

    adj = defaultdict(lambda:defaultdict(list))
    reachable = [[False] * V for _ in range(V)]
    upper = [inf] * V

    for _ in range(E):
        u, v, c = [int(x) for x in input().split()]
        adj[u][v].append(c)
        reachable[u][v] = True

    for here in range(V):
        reachable[here][here] = True

    for here in range(V):
        for there in range(V):
            for inter in range(V):
                if reachable[here][inter] and reachable[inter][there]:
                    reachable[here][there] = True

    if not reachable[0][1]:
        print('UNREACHABLE')
        continue

    answer = bellman_ford()
    if answer == inf:
        answer = 'UNREACHABLE'
    elif answer == -inf:
        answer = 'INFINITY'

    print(answer, end=' ')

    for u, v in adj.items():
        for key, items in v.items():
            adj[u][key] = [-x for x in items]

    upper = [inf] * V

    answer = bellman_ford()
    if answer == inf:
        answer = 'UNREACHABLE'
    elif answer == -inf:
        answer = 'INFINITY'
    else:
        answer *= -1

    print(answer)

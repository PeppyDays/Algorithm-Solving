from collections import defaultdict

N, E = int(input()), int(input())
counter = 1

adj = defaultdict(list)
discovered = [False] * N
finished = [False] * N

for e in range(E):
    i, j = [int(x) for x in input().split()]
    adj[i].append(j)


def dfs2(here):
    global counter, discovered, finished

    discovered[here] = counter
    counter += 1

    for there in adj.get(here, []):
        print(here, 'to', there, 'is a', end=' ')

        if not discovered[there]:
            print('tree edge')
            dfs2(there)
        elif discovered[here] < discovered[there]:
            print('forward edge')
        elif finished[there]:
            print('cross edge')
        else:
            print('back edge')

    finished[here] = True

dfs2(0)

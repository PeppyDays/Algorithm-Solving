from collections import defaultdict
import math

INF = math.inf
V = 3
adj = {0: {1: 7, 2: 5}, 1: {2: -15}}


def bellman_ford(src):
    # 각 노드별 거리를 무한으로 설정하고, 시작점만 0 으로 설정한다.
    upper = [INF] * V
    upper[src] = 0
    parents = [None] * V
    parents[src] = src
    # 모든 노드에서 완화가 실패할 경우를 저장한다.
    updated = False

    for _ in range(V):
        updated = False
        for here in range(V):
            for there, dist_here_to_there in adj.get(here, {}).items():
                if upper[there] > upper[here] + dist_here_to_there:
                    # 완화 성공
                    upper[there] = upper[here] + dist_here_to_there
                    parents[there] = here
                    updated = True

        # 한번도 완화가 이루어지지 않았다면 그만한다.
        if not updated:
            break

    # V번째 순회에서도 완화가 성공했다면, 음수 사이클이 존재한다
    if updated:
        upper = []
        parents = []

    return upper, parents


upper, parents = bellman_ford(0)
print(upper)
print(parents)

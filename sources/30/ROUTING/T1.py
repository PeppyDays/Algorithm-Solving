# 문제 링크
# https://algospot.com/judge/problem/read/ROUTING


from collections import defaultdict
from queue import PriorityQueue


def dijkstra(start):
    """
    Dijkstra 알고리즘을 통해 start -> 각 노드 별 distance 를 구한다.
    :param start: Dijkstra 알고리즘을 수행할 시작 노드 위치
    :return: start -> 각 노드별 distance
    """

    # adj[i][j] = c: i -> j 로 연결된 간선의 cost 는 c 이다.
    # N: 전체 노드 수
    global adj, N

    # dist: start -> i 번째 노드까지 걸리는 최소 cost
    dist = [None] * N
    q = PriorityQueue()
    dist[start] = 1.0
    q.put((1.0, start))

    while not q.empty():
        cost_to_here, here = q.get()

        # PQ 에서 꺼낸 값이 이미 방문된, 최소 cost 보다 큰 경우는 Skip 한다.
        if dist[here] is not None and dist[here] < cost_to_here:
            continue

        # here 에 연결된 there 노드별로 최소 cost 를 다시 한 번 구해본다.
        for there, cost_here_to_there in adj.get(here, {}).items():
            if dist[there] is None or dist[there] > cost_to_here * cost_here_to_there:
                dist[there] = cost_to_here * cost_here_to_there
                q.put((dist[there], there))

    return dist


T = int(input())

for t in range(T):
    N, M = [int(x) for x in input().split()]
    adj = defaultdict(dict)

    for _ in range(M):
        u, v, c = [float(x) for x in input().split()]
        u, v = int(u), int(v)
        adj[u][v] = c;
        adj[v][u] = c;

    d = dijkstra(0)
    print('{0:.10f}'.format(d[-1]))

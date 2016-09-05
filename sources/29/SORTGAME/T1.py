# 문제 링크
# https://algospot.com/judge/problem/read/SORTGAME

from queue import Queue


def pre_calculate(n, distance):
    """
    (0, 1, 2, .. , n-1) 부터 변경 가능한 모든 케이스에 대해서 거리 계산
    :param n: # of vertexes
    :param distance: origin -> 대상 점까지의 거리 정보를 저장할 dictionary
    :return: None
    """

    # 시작 지점을 (0, 1, .. , n-1) 로 시작한다.
    start = tuple(range(n))
    q = Queue()
    q.put(start)
    distance[start] = 0

    while not q.empty():
        here = list(q.get())

        # 현재 위치에서 변경할 수 있는 모든 종류의 변경을 하고,
        # 새로 나온 there 위치가 distance 에 없다면 모두 queue 에 넣어서 처리한다.
        for i in range(n-1):
            for j in range(i+1, n+1):
                pre, mid, post = here[:i], here[i:j], here[j:]
                mid.reverse()
                there = tuple(pre + mid + post)

                if there not in distance:
                    distance[there] = distance[tuple(here)] + 1
                    q.put(there)


def solve(end, distance):
    """
    문제에서 제시된 위치를 (0, 1, .. , n-1) 형식으로 변환하고,
    위에서 미리 구한 distance dictionary 를 통해 답을 구한다.
    :param end: 문제에 제시된 위치
    :param distance: origin -> 모든 점 까지의 거리 dictionary
    :return: 가장 가까운 거리
    """

    n = len(end)
    fixed = [None] * N

    # i 위치보다 앞에 있는 j 들을 확인해서, 내 현재 순번을 확인해서 그 값으로 fixed 에 저장한다.
    # 왜? 위에서 구한 map 을 사용하기 위해서
    for i in range(n):
        smaller = 0
        for j in range(n):
            if end[i] > end[j]:
                smaller += 1
        fixed[i] = smaller

    return distance[tuple(fixed)]


for _ in range(int(input())):
    N = int(input())
    end = tuple([int(x) for x in input().split()])
    distance = {}

    pre_calculate(N, distance)
    print(solve(end, distance))

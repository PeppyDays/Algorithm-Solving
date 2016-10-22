# 문제 링크
# https://algospot.com/judge/problem/read/CHILDRENDAY

from queue import Queue


def gifts():
    """
    N 명의 학생(중 M 명은 욕심쟁이)에게 나누어줄 선물 개수를 구한다.
    :return: 선물 개수
    """

    global digits, N, M

    # 접근하는 노드 순서가 정렬되어야 작은 수가 앞으로 나와서 전체 결과가 정렬될 수 있다.
    digits.sort()

    # parent: BFS 트리에서 i 노드의 부모를 저장하는 변수
    # choice: BFS 트리에서 i 노드에 오기 위해 거친 간선의 번호
    parent = [None] * 2 * N
    choice = [None] * 2 * N
    q = Queue()

    # 0번 부터 시작해서 m번으로 도착해야 한다.
    q.put(0)
    parent[0] = 0

    while not q.empty():
        here = q.get()

        # N + M 번 째 노드를 찾으면 뒤에는 의미없으므로 중단한다.
        if here == N + M:
            break

        # 뒷 자리에 숫자를 추가해나간다.
        for digit in digits:
            # 다음 자리는 (현재 나머지 * 10 + 더하는 숫자) 를 학생 수로 나눈다.
            # N 보다 큰 경우는 회색으로 진입한 경우!
            there = here * 10 + digit
            there = (N + there % N) if there >= N else there % N

            if parent[there] is None:
                parent[there] = here
                choice[there] = digit
                q.put(there)

    here = N + M
    if parent[here] is None:
        return 'IMPOSSIBLE'

    ret = ''
    while parent[here] != here:
        ret += str(choice[here])
        here = parent[here]

    ret = ret[::-1]
    return ret


T = int(input())

for t in range(T):
    digits, N, M = input().split()
    digits = [int(x) for x in digits]
    N, M = int(N), int(M)

    print(gifts())

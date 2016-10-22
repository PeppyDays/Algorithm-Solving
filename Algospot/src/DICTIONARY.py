# 문제 링크
# https://algospot.com/judge/problem/read/DICTIONARY

Alphabet = 'abcdefghijklmnopqrstuvwxyz'


def make_adj_map(words):
    """
    단어 리스트에서 Adjacent Map 을 만드는 함수
    :param words: 단어 리스트
    :return: Async Graph 인지 아닌지?, Adjacent Map 이중 리스트
    """

    # Adjacent Map
    adj_map = {}

    # 단어를 앞뒤만 비교하여, 문자의 선후행 관계 검색
    for w1, w2 in zip(words, words[1:]):
        for c1, c2 in zip(w1, w2):
            if c1 == c2:
                continue

            # c1 보다 큰 문자열들을 set 에 저장
            adj_map.setdefault(c1, set()).add(c2)

            # 발견되면 뒤의 문자는 의미가 없으므로 for 문 종료
            break

    # Graph 에 Loop 가 있는지 확인
    # 이 경우에는 여러 노드를 거쳐서 Loop 가 생기는 경우가 없으므로, i -> j 와 j -> i 가 동시에 생기는지 확인
    for k, vs in adj_map.items():
        for v in vs:
            if k in adj_map.get(v, []):
                return False, adj_map

    return True, adj_map


def dfs(here):
    """
    DFS 탐색
    :param here: 현재 방문한 노드의 위치
    :return: None
    """

    global Seen, AdjMap, Trail

    Seen[here] = True

    for there in AdjMap.get(here, []):
        if not Seen[there]:
            dfs(there)

    Trail.append(here)


for t in range(int(input())):
    # N: 판단할 단어의 개수
    # Words: 입력받은 단어 리스트
    N = int(input())
    Words = [input() for _ in range(N)]

    # Adjacent Map 생성
    is_async, AdjMap = make_adj_map(Words)

    # Graph 에 Loop 가 있다면, INVALID HYPOTHESIS 출력하고 다음 테스트 수행
    if not is_async:
        print('INVALID HYPOTHESIS')
        continue

    # Seen: DFS 에서 방문한 노드 체크, True 는 방문했음
    # TopSort: 위상정렬 결과
    Seen = {c: False for c in Alphabet}
    Trail = []

    # DFS 를 통해 위상정렬 수행, ABC..부터 출력되게 하기 위해 역순으로 조회, range(26) 해도 상관없음
    for here in Alphabet:
        if not Seen[here]:
            dfs(here)

    # DFS 를 통해 얻은 위상정렬은 뒤집어주고, 문자로 표시
    Trail.reverse()

    # 테스트 정답 출력
    print(''.join(Trail))

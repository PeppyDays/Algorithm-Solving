# 문제 링크
# https://algospot.com/judge/problem/read/WORDCHAIN


def make_graph(words):
    """
    입력받은 단어로부터 그래프 정보를 추출해서 리턴
    :param words: 입력받은 단어 list
    :return: 단어 리스트로부터 추출한 Adj Map, 각 노드별 In/Out 간선 수
    """

    adj_map = {}
    in_degree, out_degree = {}, {}

    for word in words:
        start_c = word[0]
        end_c = word[-1]
        # adj_map: {시작문자1: {끝문자1: [단어1, 단어2 ..], 끝문자: [..], }, 시작문자: .. , }
        adj_map.setdefault(start_c, dict()).setdefault(end_c, list()).append(word)
        # in_degree: {노드문자: 나가는 횟수, }
        in_degree[end_c] = in_degree.setdefault(end_c, 0) + 1
        # out_degree: {노드 문자: 들어오는 횟수, }
        out_degree[start_c] = out_degree.setdefault(start_c, 0) + 1

    return adj_map, in_degree, out_degree


def check_graph_as_euler(in_degree, out_degree):
    """
    노드의 In/Out 횟수를 보고, 오일러 트레일이 가능한지 확인한다.
    :param in_degree: 노드별 들어오는 간선의 수
    :param out_degree: 노드별 나가는 간선의 수
    :return: 오일러 트레일 혹은 오일러 서킷이 가능한지? 트레일인지 서킷인지? 어떤 문자 노드인지?
    """

    # 단어 노드에서 In 횟수와 Out 횟수가 다른 경우를 추출
    in_out_diff = {
        k: (in_degree.get(k, 0) - out_degree.get(k, 0)) for k in in_degree.keys() | out_degree.keys()
        if in_degree.get(k, 0) != out_degree.get(k, 0)
    }

    # 비어있다면? 서킷, {-1, 1} 과 같다면? 트레일, 나머지는 오일러 불가능
    if not in_out_diff:
        return True, {
            'type': 'CIRCUIT',
        }
    elif len(in_out_diff) is 2 and set(in_out_diff.values()) == {1, -1}:
        ret_start_node = [k for k, v in in_out_diff.items() if v is -1][0]
        return True, {
            'type': 'TRAIL',
            'start_node': ret_start_node,
        }
    else:
        return False, None


def find_euler_circuit(here, adj_map):
    """
    오일러 서킷 혹은 트레일을 찾고, 노드가 아니라 간선을 역순으로 출력한다.
    :param here: 현재 노드의 문자
    :param adj_map: 현재-다음 노드 문자의 연결 관계
    :return: 오일러 서킷 혹은 트레일을 돌았을 때의 간선 경로
    """

    circuit = []

    # here 에 연결된 다음 there 노드를 찾아서 간선의 단어를 저장하고, there 로 이동해서 다시 dfs 를 수행한다.
    # here 에 연결된 다음 노드가 다시 here 가 존재하는 경우 이 것 부터 실행해야 한다.
    for there in adj_map.get(here, []):
        if there == here:
            continue

        try:
            v_word = adj_map[here][there].pop()
        except IndexError:
            continue

        circuit = find_euler_circuit(there, adj_map)
        circuit.append(v_word)

    for self_word in adj_map.get(here, []).get(here, []):
        circuit.append(self_word)

    adj_map[here][here] = []

    return circuit


# 메인문 시작
for t in range(int(input())):
    # Words: 입력받은 단어들
    Words = [input() for _ in range(int(input()))]

    # Adj Map, 각 노드별 In/Out 간선 수 구하기
    adj_map, in_degree, out_degree = make_graph(Words)

    # Euler 로 한붓그리기가 되는지 안되는지 판단하기
    is_euler, euler_type = check_graph_as_euler(in_degree, out_degree)

    # 만약 Euler 가 아니라면? IMPOSSIBLE 출력
    if not is_euler:
        print('IMPOSSIBLE')
        continue

    # Euler 를 순회 시작할 노드 찾기
    start_node = euler_type.get('start_node', Words[0][0])

    # Euler Circuit 순회
    circuit = find_euler_circuit(start_node, adj_map)
    circuit.reverse()

    print(' '.join(circuit))

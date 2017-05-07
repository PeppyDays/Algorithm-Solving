#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// here 에서 시작해서 도달할 수 있는 노드 중 가장 발견순서가 빠른 노드의 발견순서를 출력
int findCutVertex(int here, bool isRoot, int& counter, vector<vector<int> >& adj, vector<int>& discovered, vector<bool>& isCutVertex);

int main() {
    ios_base::sync_with_stdio(false);
    freopen("/Users/Donald/Documents/Algorithm-Solving/resources/input.in", "r", stdin);

    int n, e;
    cin >> n >> e;

    vector<vector<int> > adj(n);

    for (int i = 0; i < e; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int counter = 0;
    vector<int> discovered(n, -1);
    vector<bool> isCutVertex(n);

    int start = 0;
    findCutVertex(start, true, counter, adj, discovered, isCutVertex);

    for (int i = 0; i < n; ++i)
        cout << isCutVertex[i] << ' ';

    return 0;
}

int findCutVertex(int here, bool isRoot, int& counter, vector<vector<int> >& adj, vector<int>& discovered, vector<bool>& isCutVertex) {
    // here 노드의 발견순서 저장
    discovered[here] = counter++;

    // ret: here 에서 갈 수 있는 제일 빠른 발견순서, 우선 현재 노드의 발견순서로 초기화
    int ret = discovered[here];

    // root 일 경우는 child 개수를 확인해야 하므로, childCnt 에 child 개수 저장
    int childCnt = 0;

    // 인접 노드 탐색
    for (int i = 0; i < adj[here].size(); ++i) {
        // there: here 에 연결된 노드
        int there = adj[here][i];

        // there 가 아직 발견되지 않았다면? tree edge, 직접 연결된 child
        if (discovered[there] == -1) {
            // child 개수 1 추가
            ++childCnt;
            // subRet: there 에서 접근할 수 있는 제일 빠른 발견순서 찾기
            int subRet = findCutVertex(there, false, counter, adj, discovered, isCutVertex);

            // here 가 root 가 아니고,
            // there 가 접근할 수 있는 제일 빠른 발견순서가 here 의 발견순서보다 밑이라면?
            // 즉, 역방향 간선이 없다면?
            // 모든 child 에 역방향 간선이 있어야 단절점이 아닌데, 1개라도 역방향 간선이 없다면 단절점임
            if (!isRoot && subRet >= discovered[here])
                isCutVertex[here] = true;
            
            // here 에서 갈 수 있는 가장 빠른 발견순서 업데이트
            ret = min(ret, subRet);
        }
        // there 가 발견된 곳이었다면?
        // 방향이 없는 그래프이므로 무조건 there 는 here 의 조상이다.
        // 그러므로 갈 수 있는 발견순서 부분만 업데이트 하자.
        else {
            ret = min(ret, discovered[there]);
        }
    }

    // 만약 here 가 root 라면, child 개수에 따라 단절점 여부가 정의된다.
    if (isRoot)
        isCutVertex[here] = (childCnt >= 2);
    
    return ret;
}
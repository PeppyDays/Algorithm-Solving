#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXV 10010
int V, E, counter=0, discovered[MAXV];
bool isCutVertex[MAXV];
vector<int> graph[MAXV];

int dfs(int A, bool isRoot){
    discovered[A]= ++counter;
    int ret = discovered[A];

    int child=0; //정점 A가 루트 노드 일 경우를 대비해서 DFS스패닝 트리에서의 자식 수 세어준다.
    for(int i = 0 ;  i< (int)graph[A].size() ; i++){
        int next = graph[A][i];
        if(!discovered[next]){
            child++;
            //low : 정점 A의 자식 노드가 갈 수 있는 노드중 가장 일찍 방문한 노드
            int low = dfs(next, false);
            if(!isRoot && low >= discovered[A])
                isCutVertex[A] = true;
            ret=  min(ret, low);
        }else{
            ret = min(ret, discovered[next]);
        }
    }

    if(isRoot)
        isCutVertex[A] = (child >=2);
    return ret;
}

int main(){
    scanf("%d%d", &V, &E);
    for(int i =1 ; i<= E; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i = 1; i <= V; i++){
        if(!discovered[i])
            dfs(i, true);
    }

    int cnt=0;
    for(int i = 1 ; i<= V; i++){
        if(isCutVertex[i])
            cnt++;
    }
    printf("%d\n", cnt);
    for(int i =1 ; i<= V; i++){
        if(isCutVertex[i])
            printf("%d ", i);
    }
    return 0;
}

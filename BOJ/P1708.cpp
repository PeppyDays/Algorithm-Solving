#include <iostream>
#include <stack>
#include <tuple>
#include <algorithm>
using namespace std;

class Point {
    int x, y;
    double angle;
};

const int MaxN = 100000;

// c 가 a - b 직선의 왼쪽에 있거나 같은 선 상에 있다면 True, 아니면 False
bool ccw(const Point& a, const Point& b, const Point& c) {
    return (b.x - a.x) * (c.y - a.y) < (b.y - a.y) * (c.x - a.x);
}

int main() {
    freopen("resources/input.in", "r", stdin);
    ios_base::sync_with_stdio(false);

    int N;
    Point P[MaxN];

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> P[i].x >> P[i].y;

    // 가장 y 가 작고, x 가 작은 기준점을 P[0] 으로
    sort(P, P + N);

    // 기준점을 원점으로 만들도록 좌표 조정
    for (int i = 1; i < N; ++i) {
        P[i].first -= P[0].first;
        P[i].second -= P[0].second;
    }

    // P[0] 을 제외한 점들을 반시계 방향으로 정렬







    return 0;
}



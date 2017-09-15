#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

typedef pair<int, int> couple;

int N;
vector<couple> Rect;
vector<couple> Line;
vector<long long> Cache[MaxN];

double cross(couple u, couple v) {
    return (double)(u.second - v.second) / (v.first - u.first);
}

void push(couple u) {
    while (Line.size() >= 2 && cross(u, Line.rbegin()[0]) < cross(u, Line.rbegin()[1]))
        Line.pop_back();

    Line.push_back(u);
}

int main() {
    freopen("resources/input.in", "r", stdin);
    ios_base::sync_with_stdio(false);

    cin >> N;

    for (int i = 1; i <= N; ++i)
        cin >> Rect[i].first >> Rect[i].second;

    sort(Rect + 1, Rect + N + 1);

    stack<couple> s;
    for (int i = 1; i <= N; ++i) {
        while (!s.empty() && Rect[i].second > s.top().second)
            s.pop();

        s.push(Rect[i]);
    }

    N = 0;
    while (!s.empty()) {
        Rect[N + 1] = s.top();
        s.pop();
        N += 1;
    }

    // for (int i = 1; i <= N; ++i)
    //     cout << Rect[i].first << ' ' << Rect[i].second << endl;







    return 0;
}

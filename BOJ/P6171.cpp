#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

typedef pair<int, int> couple;
// const int MaxN = 50000;
// const int MaxL = 1000000;
const int MaxN = 10;
const int MaxL = 100;

int N;
long Cache[MaxN];
couple Rect[MaxN];

int main() {
    freopen("resources/input.in", "r", stdin);
    ios_base::sync_with_stdio(false);

    cin >> N;

    for (int i = 0; i < N; ++i)
        cin >> Rect[i].first >> Rect[i].second;

    sort(Rect, Rect + N);

    stack<couple> s;
    for (int i = 0; i < N; ++i) {
        while (!s.empty() && Rect[i].second < s.top().second)
            s.pop();

        s.push(Rect[i]);
    }

    N = 0;
    while (!s.empty()) {
        Rect[N] = s.top();
        s.pop();
        N += 1;
    }

    for (int i = 0; i < N; ++i)
        cout << Rect[i].first << ' ' << Rect[i].second << endl;


    return 0;
}

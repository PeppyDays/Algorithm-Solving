#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> couple;

int N;
vector<couple> lines;
vector<int> lis;

int main() {
    freopen("resources/input.in", "r", stdin);

    scanf("%d", &N);
    int u, v;
    for (int i = 0; i < N; ++i) {
        scanf("%d %d", &u, &v);
        lines.push_back(make_pair(u, v));
    }

    sort(lines.begin(), lines.end());

    for (int i = 0; i < N; ++i) {
        vector<int>::iterator it = lower_bound(lis.begin(), lis.end(), lines[i].second);

        if (it == lis.end())
            lis.push_back(lines[i].second);
        else
            *it = lines[i].second;
    }

    cout << N - lis.size() << endl;

    return 0;
}
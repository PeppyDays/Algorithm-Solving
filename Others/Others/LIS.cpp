#include <iostream>
#include <vector>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();

int main() {
    ios_base::sync_with_stdio(false);
    freopen("resources/input.in", "r", stdin);

    int N;
    cin >> N;
    vector<int> A(N), P(N);
    vector<pair<int, int> > T;
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    for (int i = 0; i < N; ++i) {
        pair<int, int> x = make_pair(A[i], i);
        int idx = lower_bound(T.begin(), T.end(), x) - T.begin();
        if (idx != T.size())
            T[idx] = x;
        else
            T.push_back(x);

        if (idx == 0)
            P[i] = -1;
        else
            P[i] = T[--idx].second;
    }

    cout << T.size() << endl;
    int idx = (--T.end()) -> second;
    while (idx != -1) {
        cout << A[idx] << ' ';
        idx = P[idx];
    }

    return 0;
}
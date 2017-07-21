#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(vector<int>& A, int idx, vector<int>& s);
void print(vector<int> s);

int main() {
    freopen("resources/input.in", "r", stdin);
    ios_base::sync_with_stdio(false);

    int N;
    vector<int> A(49);
    vector<int> s;

    cin >> N;

    do {
        A.resize(N);
        s.clear();

        for (int i = 0; i < N; ++i)
            cin >> A[i];

        sort(A.begin(), A.begin() + N);
        dfs(A, 0, s);

        cin >> N;
        cout << '\n';
    }
    while (N != 0);

    return 0;
}

void print(vector<int> s) {
    for (int i = 0; i < s.size(); ++i)
        cout << s[i] << ' ';
    cout << '\n';
}

void dfs(vector<int>& A, int idx, vector<int>& s) {
    if (s.size() == 6)
        print(s);

    if (idx >= A.size())
        return;

    for (int i = idx; i < A.size(); ++i) {
        s.push_back(A[i]);
        dfs(A, i + 1, s);
        s.pop_back();
    }

    return;
}
#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <vector>
using namespace std;

int N, M;

int main() {
    freopen("/Users/donald/Documents/workspace/AlgorithmSolving/AlgorithmSolving/input.in", "r", stdin);
//    freopen("/Users/donald/Documents/workspace/AlgorithmSolving/AlgorithmSolving/output.out", "w", stdout);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    set<string> n;
    set<string> m;
    string temp;
    vector<string> v;

    for (int i = 0; i < N; ++i) {
        cin >> temp;
        n.insert(temp);
    }

    for (int i = 0; i < M; ++i) {
        cin >> temp;
        m.insert(temp);
    }

    for (set<string>::iterator it=m.begin(), end=m.end(); it != end; ++it) {
        if (n.find(*it) != n.end())
            v.push_back(*it);
    }

    cout << v.size() << '\n';
    for (vector<string>::iterator it = v.begin(), end = v.end(); it != end; ++it)
        cout << *it << '\n';

    return 0;
}

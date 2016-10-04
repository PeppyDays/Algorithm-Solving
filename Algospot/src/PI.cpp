#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <string>
using namespace std;

static int INF = numeric_limits<int>::max();

int N;
vector<int> Pi;
vector<int> Cache;

int strLevel(int s, int e);
int memorizePi(int start);

int main() {
    ios_base::sync_with_stdio(false);
//    freopen("/Users/donald/ClionProjects/AlgorithmSolving/input.in", "r", stdin);

    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        string token;
        cin >> token;

        N = token.length();
        Pi.resize(N);
        Cache.resize(N);
        fill(Cache.begin(), Cache.end(), -2);

        for (int i = 0; i < N; ++i)
            Pi[i] = token[i] - '0';

        cout << memorizePi(0) << '\n';
    }

    return 0;
}

int strLevel(int s, int e) {
    bool updated = false;

    // Lv 1
    for (int i = s, init = Pi[s]; i < e; ++i) {
        if (Pi[i] != init) {
            updated = true;
            break;
        }
    }

    if (!updated)
        return 1;

    // Lv 2
    updated = false;
    int delta = Pi[s + 1] - Pi[s];

    if (delta == 1 || delta == -1) {
        for (int i = s + 1; i < e; ++i) {
            if (Pi[i] - Pi[i - 1] != delta) {
                updated = true;
                break;
            }
        }

        if (!updated)
            return 2;
    }

    // Lv 3
    updated = false;
    int rolling[2] = { Pi[s], Pi[s + 1] };

    for (int i = 0; i < e - s; ++i) {
        if (Pi[s + i] != rolling[i % 2]) {
            updated = true;
            break;
        }
    }

    if (!updated)
        return 4;

    // Lv 4
    updated = false;
    delta = Pi[s + 1] - Pi[s];

    for (int i = s + 1; i < e; ++i) {
        if (Pi[i] - Pi[i - 1] != delta) {
            updated = true;
            break;
        }
    }

    if (!updated)
        return 5;

    return 10;
}

int memorizePi(int start) {
    if (start > N - 3)
        return -1;

    int& ret = Cache[start];
    if (ret != -2)
        return ret;

    if (start > N - 6) {
        ret = strLevel(start, N);
        return ret;
    }

    ret = -1;

    for (int i = 3; i < 6; ++i) {
        int sub_result = memorizePi(start + i);

        if (sub_result == -1)
            continue;

        if (ret == -1)
            ret = sub_result + strLevel(start, start + i);
        else
            ret = min(ret, sub_result + strLevel(start, start + i));
    }

    return ret;
}

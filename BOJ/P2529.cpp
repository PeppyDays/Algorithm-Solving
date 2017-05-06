#include <iostream>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <stdio.h>
using namespace std;

int n;
char relation[9];
bool visited[10];

string toString(int v);
string toStringByStdio(int v);
pair<bool, string> dfs(int here, int relationIdx, int delta);

int main() {
    ios_base::sync_with_stdio(false);
    freopen("/Users/Donald/Documents/Algorithm-Solving/resources/input.in", "r", stdin);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> relation[i];
    
    string minRet = "9999999999";
    string maxRet = "0000000000";

    for (int here = 0; here < 10; ++here) {
        memset(visited, 0, sizeof(visited));
        pair<bool, string> ret = dfs(here, 0, 1);

        if (ret.first) {
            minRet = min(minRet, ret.second);
            break;
        }
    }

    for (int here = 9; here >= 0; --here) {
        memset(visited, 0, sizeof(visited));
        pair<bool, string> ret = dfs(here, 0, -1);

        if (ret.first) {
            maxRet = max(minRet, ret.second);
            break;
        }
    }
    
    cout << maxRet << '\n';
    cout << minRet << '\n';

    return 0;
}

string toStringByStdio(int v) {
    char buf[5];
    sprintf(buf, "%d", v);
    return string(buf);
}

string toString(int v) {
    stringstream stream;
    stream << v;
    return stream.str();
}

pair<bool, string> dfs(int here, int relationIdx, int delta) {
    if (relationIdx == n)
        return make_pair(true, toStringByStdio(here));

    visited[here] = true;
    pair<bool, string> ret = make_pair(false, toStringByStdio(here));

    int start, end;
    if (relation[relationIdx] == '>') {
        start = 0;
        end = here - 1;
    }
    else {
        start = here + 1;
        end = 9;
    }

    if (delta == 1) {
        for (int there = start; there <= end; ++there) {
            if (visited[there])
                continue;

            pair<bool, string> subRet = dfs(there, relationIdx + 1, delta);
            if (subRet.first) {
                ret.first = true;
                ret.second.append(subRet.second);
                break;
            }
        }
    }
    else {
        for (int there = end; there >= start; --there) {
            if (visited[there])
                continue;

            pair<bool, string> subRet = dfs(there, relationIdx + 1, delta);
            if (subRet.first) {
                ret.first = true;
                ret.second.append(subRet.second);
                break;
            }
        }
    }

    visited[here] = false;
    return ret;
}
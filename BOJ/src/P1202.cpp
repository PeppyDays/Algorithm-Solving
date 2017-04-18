#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> couple;
const int MaxN = 300000;
const int MaxK = 300000;

int n, k;
couple jewel[MaxN];
int bag[MaxK];

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> jewel[i].first >> jewel[i].second;
    for (int i = 0; i < k; ++i)
        cin >> bag[i];

    sort(jewel, jewel + n);
    sort(bag, bag + k);

    priority_queue<int> pq;
    long long Answer = 0;

    for (int bagNo = 0, jewelNo = 0; bagNo < k; ++bagNo) {
        while (jewelNo < n && jewel[jewelNo].first <= bag[bagNo])
            pq.push(jewel[jewelNo++].second);

        if (pq.empty())
            continue;

        Answer += pq.top();
        pq.pop();
    }

    cout << Answer;

    return 0;
}


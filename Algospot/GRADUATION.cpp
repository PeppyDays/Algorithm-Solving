#include <iostream>
#include <algorithm>
#include <limits>
#include <bitset>
#include <cstring>
using namespace std;

const int INF = numeric_limits<int>::max() - 1;
const int MaxN = 12;
const int MaxM = 10;

// N: 총 과목의 수
// K: 들어야할 과목의 수
// M: 학기의 수
// L: 한 학기에 최대로 들을 수 있는 과목의 수
int N, K, M, L;

// R[i]: i 과목의 선수과목들의 bitset
int R[MaxN];

// C[i]: i번째 학기에 개설되는 과목들의 bitset
int C[MaxM];

// Cache
int Cache[MaxM][1 << MaxN];

// 현재 학기가 semester 이고, 지금까지 taken 과목들을 들었을 때, 다녀야 하는 최소 학기의 수
int graduate(int semester, int taken);

int main() {
    freopen("/Users/donald/Documents/workspace/AlgorithmSolving/AlgorithmSolving/input.in", "r", stdin);
    // freopen("/Users/donald/Documents/workspace/AlgorithmSolving/AlgorithmSolving/output.out", "w", stdout);

    int T;
    cin >> T;

    while (T--) {
        memset(Cache, -1, sizeof(Cache));
        memset(R, 0, sizeof(R));
        memset(C, 0, sizeof(C));

        cin >> N >> K >> M >> L;

        for (int i = 0; i < N; ++i) {
            int preClassCnt, preClassIdx;
            cin >> preClassCnt;

            while (preClassCnt--) {
                cin >> preClassIdx;
                R[i] |= (1 << preClassIdx);
            }
        }

        for (int i = 0; i < M; ++i) {
            int classCnt, classIdx;
            cin >> classCnt;

            while (classCnt--) {
                cin >> classIdx;
                C[i] |= (1 << classIdx);
            }
        }

        int ret = graduate(0, 0);

        if (ret == INF)
            cout << "IMPOSSIBLE" << '\n';
        else
            cout << ret << '\n';
    }

    return 0;
}

int graduate(int semester, int taken) {
//    cout << "graduate(semester:'" << semester << "', taken:'" << bitset<MaxN>(taken) << "')" << '\n';

    if (__builtin_popcount(taken) >= K) {
//        cout << "  " << "들은 과목 taken 이 K(들어야할 과목) 수를 넘은 경우이기 때문에 return 0" << '\n';
        return 0;
    }

    if (semester >= M) {
//        cout << "  " << "M 학기가 넘어서 실패했으므로 return INF" << '\n';
        return INF;
    }

    int& ret = Cache[semester][taken];
    if (ret != -1) {
//        cout << "  " << "Cache[" << semester << "][" << taken << "]" << "결과 불러옴 return " << ret << '\n';
        return ret;
    }

    ret = INF;
    int canTake = (C[semester] & (~taken));
//    cout << "  " << "C[" << semester << "]:    " << bitset<MaxN>(C[semester]) << '\n';
//    cout << "  " << "taken:   " << bitset<MaxN>(taken) << '\n';
//    cout << "  " << "canTake: " << bitset<MaxN>(canTake) << '\n';

    for (int i = 0; i < N; ++i) {
        if ((canTake & (1 << i)) && ((taken & R[i]) != R[i])) {
//            cout << "    " << "class " << i << " 선수과목 없음, 제외" << '\n';
            canTake &= ~(1 << i);
        }
    }

//    cout << "  " << "canTake: " << bitset<MaxN>(canTake) << '\n';
//    cout << "  for 문 시작" << '\n';
    for (int take = canTake; take; take = ((take - 1) & canTake)) {
//        cout << "    " << "take:" << bitset<MaxN>(take) << '\n';

        if (__builtin_popcount(take) > L) {
//            cout << "      " << "한번에 들을 수 있는 L 과목수 초과, 넘어감" << '\n';
            continue;
        }

        ret = min(ret, graduate(semester + 1, taken | take) + 1);
    }

    ret = min(ret, graduate(semester + 1, taken));

//    cout << "  " << "ret:" << ret << '\n';

    return ret;
}

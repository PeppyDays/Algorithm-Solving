#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

const int MaxN = 10000000;

class Number {
public:
    int minDivisor;
    int minDivisorCnt;
    int totDivisorCnt;

    void set(int _minDivisor, int _minDivisorCnt, int _totDivisorCnt) {
        minDivisor = _minDivisor;
        minDivisorCnt = _minDivisorCnt;
        totDivisorCnt = _totDivisorCnt;
    }
};

int c, n, lo, hi;
Number number[MaxN + 1];

int main() {
    freopen("/Users/donald/Documents/workspace/AlgorithmSolving/AlgorithmSolving/input.in", "r", stdin);
    freopen("/Users/donald/Documents/workspace/AlgorithmSolving/AlgorithmSolving/output.out", "w", stdout);

    number[0].set(-1, -1, -1);
    number[1].set(1, 1, 1);

    for (int i = 2; i <= MaxN; ++i)
        number[i].set(i, 1, 1);

    for (int i = 2; i <= int(sqrt(MaxN)); ++i) {
        if (number[i].minDivisor == i) {
            for (int j = i * i; j <= MaxN; j += i) {
                if (number[j].minDivisor == j) {
                    number[j].minDivisor = i;
                }
            }
        }
    }

    for (int i = 2; i <= MaxN; ++i) {
        if (number[i].minDivisor == i) {
            number[i].minDivisorCnt = 1;
            number[i].totDivisorCnt = 2;
        }
        else {
            int p = number[i].minDivisor;
            int m = i / p;

            if (p != number[m].minDivisor) {
                number[i].minDivisorCnt = 1;
                number[i].totDivisorCnt = number[m].totDivisorCnt * 2;
            }
            else {
                number[i].minDivisorCnt = number[m].minDivisorCnt + 1;
                number[i].totDivisorCnt = number[m].totDivisorCnt * (number[m].minDivisorCnt + 2) / (number[m].minDivisorCnt + 1);
            }
        }
    }

    cin >> c;
    while (c--) {
        cin >> n >> lo >> hi;

        int ret = 0;
        for (int i = lo; i <= hi; ++i)
            if (number[i].totDivisorCnt == n)
                ++ret;

        cout << ret << '\n';
    }

    return 0;
}

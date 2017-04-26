#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int N, K;
unsigned A;

int next();

int main() {
    freopen("/Users/donald/Documents/workspace/AlgorithmSolving/AlgorithmSolving/input.in", "r", stdin);
//    freopen("/Users/donald/Documents/workspace/AlgorithmSolving/AlgorithmSolving/output.out", "w", stdout);

    int C;
    scanf("%d", &C);

    while (C--) {
        scanf("%d %d", &K, &N);

        A = 0;
        queue<int> signal;
        int partialSum = 0, nextNum;
        int ret = 0;

        for (int tail = 0; tail < N; ++tail) {
            nextNum = next();
            signal.push(nextNum);
            partialSum += nextNum;

            while (partialSum > K) {
                partialSum -= signal.front();
                signal.pop();
            }

            if (partialSum == K)
                ret++;
        }

        printf("%d\n", ret);
    }

    return 0;
}

int next() {
    if (A == 0) {
        A = 1983;
        return 1984;
    }

    A = A * unsigned(214013) + unsigned(2531011);
    return int(A % 10000 + 1);
}

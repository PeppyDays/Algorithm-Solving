#include <cstdio>
#include <algorithm>
using namespace std;

char in[30000000];
const char* o;

void getIn() {
	o = in;
	in[fread(in, 1, sizeof(in) - 4, stdin)] = '\n';
}

int nextInt() {
	bool sign = true;
	int ret = 0;
	while ((*o < '0' || *o > '9') && *o != '-') ++o;
	if (*o == '-') { sign = false; ++o; }
	while (*o >= '0' && *o <= '9') ret = 10 * ret + *o++ - '0';
	return sign ? ret : -ret;
}

const int MaxN = 1000000;

int T, N, M, q, A[MaxN];

bool find(int* A, int n);

int main() {
    freopen("resources/input.in", "r", stdin);
	getIn();
	T = nextInt();

	while (T--) {
		N = nextInt();
		for (int i = 0; i < N; ++i)
			A[i] = nextInt();

		sort(A, A + N);

		M = nextInt();
		for (int i = 0; i < M; ++i) {
			q = nextInt();
			printf("%d\n", find(A, q));
		}
	}

	return 0;
}

bool find(int* A, int n) {
	int s = 0, e = N - 1, m;

	while (s <= e) {
		m = s + (e - s) / 2;

		if (A[m] < n) s = m + 1;
		else if (A[m] > n) e = m - 1;
		else if (A[m] == n) return true;
	}

	return false;
}
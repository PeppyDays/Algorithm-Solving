#include <iostream>
#include <algorithm>
#include <queue>
#include <sstream>
using namespace std;

typedef pair<int, int> couple;

bool prime[10000];
bool taken[10000];
int A, B;

void findPrime();
string toString(int a);
int toInt(string s);

int main() {
    ios_base::sync_with_stdio(false);

    findPrime();

    int T;
    cin >> T;

    while (T--) {
        cin >> A >> B;
        fill(taken, taken + 10000, false);

        queue<couple> q;
        q.push(couple(A, 0));
        taken[A] = true;

        while (!q.empty()) {
            int here = q.front().first;
            int distToHere = q.front().second;
            q.pop();

            if (here == B) {
                cout << distToHere << '\n';
                break;
            }

            for (int i = 0; i < 4; ++i) {
                string sHere = toString(here);

                for (int j = 0; j < 10; ++j) {
                    if (i == 0 && j == 0)
                        continue;

                    sHere[i] = 48 + j;
                    int nextHere = toInt(sHere);
                    if (prime[nextHere] && !taken[nextHere]) {
                        q.push(couple(nextHere, distToHere + 1));
                        taken[nextHere] = true;
                    }
                }
            }
        }

        if (!taken[B])
            cout << "Impossible" << '\n';
    }

    return 0;
}

void findPrime() {
    fill(prime, prime + 10000, true);

    prime[0] = false;
    prime[1] = false;

    for (int i = 2; i < 10000; ++i) {
        if (!prime[i])
            continue;

        int m = 2;
        while (i * m < 10000) {
            prime[i * m] = false;
            ++m;
        }
    }
}

string toString(int a) {
    stringstream s;
    s << a;
    return s.str();
}

int toInt(string s) {
    stringstream ss(s);
    int ret;
    ss >> ret;
    return ret;
}


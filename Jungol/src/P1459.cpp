#include <iostream>
using namespace std;

int N;
int numbers[101];
bool visited[101];

int getLoop(int here, int counter, int& first) {
    if (here == first) {
        visited[here] = true;
        return counter;
    }

    if (visited[here]) {
        return 0;
    }

    visited[here] = true;
    int ret = getLoop(numbers[here], counter + 1, first);

    if (ret == 0)
        visited[here] = false;

    return ret;
}

int main() {
    clock_t begin, end;
    begin = clock();
    freopen("input.in", "r", stdin);

    ios_base::sync_with_stdio(false);

    cin >> N;

    fill(visited, visited + sizeof(bool) * (N + 1), false);
    for (int i = 1; i <= N; i++) {
        cin >> numbers[i];
    }

    int Answer = 0;

    for (int i = 1; i <= N; ++i) {
        if (visited[i] || visited[numbers[i]] || numbers[i] < i)
            continue;

        if (i == numbers[i]) {
            visited[i] = true;
            ++Answer;
            continue;
        }

        Answer += getLoop(numbers[i], 1, i);
    }

    cout << Answer << '\n';

    for (int i = 1; i <= N; i++) {
        if (visited[i])
            cout << i << '\n';
    }

    end = clock();
    cout << "Duration(s): " << (double)(end - begin) / CLOCKS_PER_SEC << '\n';

    return 0;
}

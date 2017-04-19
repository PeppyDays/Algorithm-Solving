#include <iostream>
#include <vector>
using namespace std;

int n, w;
vector<string> name;
vector<int> volume;
vector<int> need;
vector<vector<int>> cache;
vector<string> picked;

int pack(int item, int capacity);
void reconstruct(int item, int capacity);

int main() {
    ios_base::sync_with_stdio(false);
    freopen("/Users/donald/ClionProjects/AlgorithmSolving/input.in", "r", stdin);

    int C;
    cin >> C;

    while (C--) {
        cin >> n >> w;
        name.resize(n);
        volume.resize(n);
        need.resize(n);
        cache.resize(n);
        picked.clear();

        for (int i = 0; i < n; i++) {
            cache[i].resize(w + 1);
            fill(cache[i].begin(), cache[i].begin() + (w + 1), -1);
        }
        for (int i = 0; i < n; i++)
            cin >> name[i] >> volume[i] >> need[i];

        int max_need = pack(0, w);
        reconstruct(0, w);

        cout << max_need << ' ' << picked.size() << '\n';
        for (string item : picked)
            cout << item << '\n';
    }

    return 0;
}

int pack(int item, int capacity) {
    if (item == n)
        return 0;

    int& ret = cache[item][capacity];
    if (ret != -1)
        return ret;

    ret = pack(item + 1, capacity);
    if (capacity >= volume[item])
        ret = max(ret, pack(item + 1, capacity - volume[item]) + need[item]);

    return ret;
}

void reconstruct(int item, int capacity) {
    if (item == n)
        return;

    if (pack(item, capacity) == pack(item + 1, capacity))
        reconstruct(item + 1, capacity);
    else {
        picked.push_back(name[item]);
        reconstruct(item + 1, capacity - volume[item]);
    }

    return;
}
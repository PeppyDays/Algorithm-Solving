#include <cstdio>
#include <utility>
using namespace std;

typedef pair<int, bool> couple;

class stack {
public:
    couple data[40];
    int idx;

    stack() { idx = 0; }

    void push(char v) { data[idx++] = make_pair(v, true); }
    void push(int v){ data[idx++] = make_pair(v, false); }
    void pop() { --idx; }
    couple top() { return data[idx - 1]; };
    bool empty() { return idx == 0; };
    int size() { return idx; };
};

int main() {
    freopen("resources/input.in", "r", stdin);
    char in[31];
    scanf("%s", in);

    stack s;
    bool normal = true;

    for (int i = 0; i < 31; ++i) {
        if (in[i] != '(' && in[i] != ')' && in[i] != '[' && in[i] != ']')
            break;

        if (in[i] == '(' || in[i] == '[')
            s.push(in[i]);
        else {
            int subRet = 0;

            while (!s.empty() && !s.top().second) {
                subRet += s.top().first;
                s.pop();
            }

            if (!subRet)
                subRet = 1;

            if (!s.empty() && s.top().second && ((s.top().first == '(' && in[i] == ')') || (s.top().first == '[' && in[i] == ']'))) {
                s.pop();
                s.push((in[i] == ')' ? 2 : 3) * subRet);
            }
            else {
                normal = false;
                break;
            }
        }
    }

    if (!normal)
        printf("%d\n", 0);
    else {
        int ret = 0;
        while (!s.empty() && !s.top().second) {
            ret += s.top().first;
            s.pop();
        }

        if (s.empty())
            printf("%d\n", ret);
        else
            printf("%d\n", 0);
    }

    return 0;
}

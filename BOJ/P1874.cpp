#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int n, number, rear = 1, flag = 0, stack[100001], top = 0, front = 0;
    char No[200002];
    cin >> n;
    for (int i = 0; i<n; i++) {
        cin >> number;
        // 입력된 숫자가 전체 크기보다 크거나 stack[top] 보다 작은 수가 입력된 경우는 NO
        if (number > n || stack[top] > number) { flag = 1; break; }
        while (rear <= number) {
            // 낮은 숫자부터 쭉 push
            stack[++top] = rear++;
            No[front++] = '+';
        }
        // 그리고 pop
        top--;
        No[front++] = '-';
    }
    if (flag == 1) {
        cout << "NO" << '\n';
    }
    else {
        for (int i = 0; i<front; i++)
            cout << No[i] << '\n';
    }
}

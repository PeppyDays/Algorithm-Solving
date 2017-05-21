#include <cstdio>
using namespace std;

const int MaxN = 1000;

template <typename T>
class queue {
public:
    T data[MaxN];
    int front, rear;

    queue() {
        front = 0;
        rear = 0;
    }

    void push(T n) {
        data[rear++] = n;
    }

    void pop() {
        front++;
    }

    T top() {
        return data[front];
    }

    bool empty() {
        return front == rear;
    }

    int size() {
        return rear - front;
    }
};

int main() {

    return 0;
}
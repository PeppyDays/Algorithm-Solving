#include <cstdio>
#include <algorithm>
#include <random>
using namespace std;

const int MaxN = 50000;
class Node;

typedef int KeyType;

class Node {
public:
    KeyType key;
    int priority, size;
    Node* left;
    Node* right;

    Node(const KeyType& _key) {
        key = _key;
        priority = rand();
        size = 1;
        left = NULL;
        right = NULL;
    }

    void setLeft(Node* _left) {
        left = _left;
        calcSize();
    }

    void setRight(Node* _right) {
        right = _right;
        calcSize();
    }

    void calcSize() {
        size = 1;
        if (left) size += (left -> size);
        if (right) size += (right -> size);
    }
};

typedef pair<Node*, Node*> NodePair;

int N;
int A[MaxN];
int S[MaxN];

NodePair split(Node* root, KeyType key);
Node* insert(Node* root, Node* node);
Node* merge(Node* a, Node* b);
Node* erase(Node* root, KeyType key);

Node* kth(Node* root, int k);

int main() {
    freopen("/Users/donald/Documents/workspace/AlgorithmSolving/AlgorithmSolving/input.in", "r", stdin);
//    freopen("/Users/donald/Documents/workspace/AlgorithmSolving/AlgorithmSolving/output.out", "w", stdout);

    int C;
    scanf("%d", &C);

    while (C--) {
        scanf("%d", &N);

        for (int i = 0; i < N; ++i)
            scanf("%d", S + i);

        Node* candidates = NULL;
        for (int i = 0; i < N; ++i)
            candidates = insert(candidates, new Node(i + 1));

        for (int i = N - 1; i >= 0; --i) {
            int larger = S[i];
            Node* k = kth(candidates, i + 1 - larger);
            A[i] = k -> key;
            candidates = erase(candidates, k -> key);
        }

        for (int i = 0; i < N; ++i)
            printf("%d ", A[i]);
        printf("\n");
    }

    return 0;
}

NodePair split(Node* root, KeyType key) {
    if (root == NULL)
        return NodePair(NULL, NULL);

    if ((root -> key) < key) {
        NodePair rs = split(root -> right, key);
        root -> setRight(rs.first);
        return NodePair(root, rs.second);
    }
    else {
        NodePair ls = split(root -> left, key);
        root -> setLeft(ls.second);
        return NodePair(ls.first, root);
    }
}

Node* insert(Node* root, Node* node) {
    if (root == NULL)
        return node;

    if (root -> priority < node -> priority) {
        NodePair splitted = split(root, node -> key);
        node -> setLeft(splitted.first);
        node -> setRight(splitted.second);
        return node;
    }
    else if (node -> key < root -> key) {
        root -> setLeft(insert(root -> left, node));
    }
    else {
        root -> setRight(insert(root -> right, node));
    }

    return root;
}

Node* merge(Node* a, Node* b) {
    if (a == NULL) return b;
    if (b == NULL) return a;

    if (a -> priority < b -> priority) {
        b -> setLeft(merge(a, b -> left));
        return b;
    }
    else {
        a -> setRight(merge(a -> right, b));
        return a;
    }
}

Node* erase(Node* root, KeyType key) {
    if (root == NULL) return root;

    if (root -> key == key) {
        Node* ret = merge(root -> left, root -> right);
        delete root;
        return ret;
    }

    if (key < root -> key) {
        root -> setLeft(erase(root -> left, key));
    }
    else {
        root -> setRight(erase(root -> right, key));
    }

    return root;
}

Node* kth(Node* root, int k) {
    int leftSize = (root -> left == NULL)? 0 : ((root -> left) -> size);

    if (leftSize == k - 1)
        return root;
    else if (leftSize < k - 1)
        return kth(root -> right, k - leftSize - 1);
    else
        return kth(root -> left, k);
}

#include <cstdio>
#include <algorithm>
#include <random>
using namespace std;

class Node;

typedef int KeyType;
typedef pair<Node*, Node*> NodePair;

NodePair split(Node* root, KeyType key);
Node* insert(Node* root, Node* node);
Node* merge(Node* a, Node* b);
Node* erase(Node* root, KeyType key);

int main() {
    freopen("/Users/donald/Documents/workspace/AlgorithmSolving/AlgorithmSolving/input.in", "r", stdin);
//    freopen("/Users/donald/Documents/workspace/AlgorithmSolving/AlgorithmSolving/output.out", "w", stdout);


    return 0;
}

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

    a -> setRight(merge(a -> right, b));
    return a;
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

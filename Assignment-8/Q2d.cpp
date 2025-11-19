#include<iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node* parent;
    Node(int k) {
        key = k;
        left = right = parent = nullptr;
    }
};
Node* inorderSuccessor(Node* n) {
    if (n->right) {
        n = n->right;
        while (n->left) n = n->left;
        return n;
    }
    Node* p = n->parent;
    while (p && n == p->right) {
        n = p;
        p = p->parent;
    }
    return p;
}

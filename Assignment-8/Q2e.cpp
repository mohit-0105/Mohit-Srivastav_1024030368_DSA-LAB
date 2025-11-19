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
Node* inorderPredecessor(Node* n) {
    if (n->left) {
        n = n->left;
        while (n->right) n = n->right;
        return n;
    }
    Node* p = n->parent;
    while (p && n == p->left) {
        n = p;
        p = p->parent;
    }
    return p;
}

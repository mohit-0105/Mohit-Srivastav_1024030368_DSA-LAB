#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k): key(k), left(nullptr), right(nullptr) {}
};

Node* searchRec(Node* r, int x) {
    if (!r || r->key == x) return r;
    if (x < r->key) return searchRec(r->left, x);
    return searchRec(r->right, x);
}

Node* searchIter(Node* r, int x) {
    while (r) {
        if (x == r->key) return r;
        if (x < r->key) r = r->left;
        else r = r->right;
    }
    return nullptr;
}


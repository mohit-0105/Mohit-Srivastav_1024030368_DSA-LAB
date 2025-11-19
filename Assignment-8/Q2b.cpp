#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k): key(k), left(nullptr), right(nullptr) {}
};
Node* bstMax(Node* r) {
    if (!r) return nullptr;
    while (r->right) r = r->right;
    return r;
}

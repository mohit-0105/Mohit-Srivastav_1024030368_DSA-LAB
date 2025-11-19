#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k): key(k), left(nullptr), right(nullptr) {}
};
Node* bstMin(Node* r) {
    if (!r) return nullptr;
    while (r->left) r = r->left;
    return r;
}

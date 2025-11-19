#include <iostream>
#include <climits>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

class BinaryTree {
    Node* root;
    bool isBSTUtil(Node* n, long long minV, long long maxV) {
        if (!n) return true;
        if (n->val <= minV || n->val >= maxV) return false;
        return isBSTUtil(n->left, minV, n->val) && isBSTUtil(n->right, n->val, maxV);
    }
public:
    BinaryTree() : root(nullptr) {}
    void setRoot(Node* r) { root = r; }
    Node* getRoot() { return root; }
    bool isBST() { return isBSTUtil(root, LLONG_MIN, LLONG_MAX); }
};

int main() {
    BinaryTree t;
    Node* a = new Node(10);
    Node* b = new Node(5);
    Node* c = new Node(15);
    Node* d = new Node(2);
    Node* e = new Node(12);
    a->left = b;
    a->right = c;
    b->left = d;
    c->left = e;
    t.setRoot(a);
    cout << (t.isBST() ? "Yes" : "No") << "\n";
    Node* x = new Node(10);
    Node* y = new Node(20);
    x->left = y;
    BinaryTree t2;
    t2.setRoot(x);
    cout << (t2.isBST() ? "Yes" : "No") << "\n";
    return 0;
}

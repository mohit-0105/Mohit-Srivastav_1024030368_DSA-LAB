#include <iostream>
#include <climits>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int v) {
        val = v;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
    Node* root;

    Node* insertNode(Node* r, int v) {
        if (!r) return new Node(v);
        if (v < r->val) r->left = insertNode(r->left, v);
        else if (v > r->val) r->right = insertNode(r->right, v);
        return r;
    }

    Node* findMin(Node* r) {
        while (r && r->left) r = r->left;
        return r;
    }

    Node* deleteNode(Node* r, int v) {
        if (!r) return r;
        if (v < r->val) r->left = deleteNode(r->left, v);
        else if (v > r->val) r->right = deleteNode(r->right, v);
        else {
            if (!r->left) { Node* t = r->right; delete r; return t; }
            else if (!r->right) { Node* t = r->left; delete r; return t; }
            Node* t = findMin(r->right);
            r->val = t->val;
            r->right = deleteNode(r->right, t->val);
        }
        return r;
    }

    int maxDepth(Node* n) {
        if (!n) return 0;
        int l = maxDepth(n->left);
        int r = maxDepth(n->right);
        return 1 + (l > r ? l : r);
    }

    int minDepth(Node* n) {
        if (!n) return 0;
        if (!n->left) return 1 + minDepth(n->right);
        if (!n->right) return 1 + minDepth(n->left);
        int l = minDepth(n->left);
        int r = minDepth(n->right);
        return 1 + (l < r ? l : r);
    }

    void inorderPrint(Node* n) {
        if (!n) return;
        inorderPrint(n->left);
        cout << n->val << " ";
        inorderPrint(n->right);
    }

public:
    BST() { root = nullptr; }

    void insert(int v) { root = insertNode(root, v); }

    void remove(int v) { root = deleteNode(root, v); }

    int getMaxDepth() { return maxDepth(root); }

    int getMinDepth() { return minDepth(root); }

    Node* getRoot() { return root; }

    void printInorder() { inorderPrint(root); cout << "\n"; }
};

bool isBSTUtil(Node* n, long long minV, long long maxV) {
    if (!n) return true;
    if (n->val <= minV || n->val >= maxV) return false;
    return isBSTUtil(n->left, minV, n->val) && isBSTUtil(n->right, n->val, maxV);
}

bool isBST(Node* root) {
    return isBSTUtil(root, LLONG_MIN, LLONG_MAX);
}

int main() {
    BST t;
    t.insert(50);
    t.insert(30);
    t.insert(20);
    t.insert(40);
    t.insert(70);
    t.insert(60);
    t.insert(80);

    t.printInorder();
    cout << t.getMaxDepth() << "\n";
    cout << t.getMinDepth() << "\n";
    cout << (isBST(t.getRoot()) ? "Yes" : "No") << "\n";

    t.remove(20);
    t.remove(30);
    t.remove(50);

    t.printInorder();
    return 0;
}


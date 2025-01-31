#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int val;
        Node *left;
        Node *right;

        Node(int val) {
            this->val = val;
            this->left = NULL;
            this->right = NULL;
        }
};

Node *input_tree() {
    int val;
    cin >> val;
    Node *root;

    if (val == -1) {
        root = NULL;
        return root;
    }
    root = new Node(val);
    queue<Node*> q;
    if (root) {
        q.push(root);
    }

    while (!q.empty()) {
        Node *p = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;

        Node *leftNode = (l == -1) ? NULL : new Node(l);
        Node *rightNode = (r == -1) ? NULL : new Node(r);

        p->left = leftNode;
        p->right = rightNode;

        if (p->left) {
            q.push(p->left);
        }
        if (p->right) {
            q.push(p->right);
        }
    }

    return root;
}

int max_height(Node *root) {
    if (root == NULL) {
        return 0;
    }
    int l = max_height(root->left);
    int r = max_height(root->right);
    return max(l, r) + 1;
}

int countNodes(Node *root) {
    if (root == NULL) {
        return 0;
    }
    int l = countNodes(root->left);
    int r = countNodes(root->right);
    return 1 + l + r;
}

bool isPerfectBinaryTree(Node *root) {
    if (root == NULL) {
        return true;
    }

    int depth = max_height(root);
    int totalNodes = countNodes(root);

    return totalNodes == (pow(2, depth) - 1);
}

int main() {
    Node *root = input_tree();

    if (isPerfectBinaryTree(root)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

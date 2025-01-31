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

void printLevelK(Node *root, int k) {
    if (root == NULL) {
        cout << "Invalid" << endl;
        return;
    }

    queue<Node*> q;
    q.push(root);
    int level = 0;

    while (!q.empty()) {
        int size = q.size();
        
        if (level == k) { 
            for (int i = 0; i < size; i++) {
                Node *n = q.front();
                q.pop();
                cout << n->val << " ";
            }
            cout << endl;
            return;
        }

        for (int i = 0; i < size; i++) {
            Node *n = q.front();
            q.pop();

            if (n->left) {
                q.push(n->left);
            }
            if (n->right) {
                q.push(n->right);
            }
        }
        level++;
    }

    cout << "Invalid" << endl;
}

int main() {
    Node *root = input_tree();

    int k;
    cin >> k;

    printLevelK(root, k);

    return 0;
}

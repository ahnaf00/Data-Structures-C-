#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node *left;
        Node *right;

        Node(int val)
        {
            this->val = val;
            this->left = NULL;
            this->right = NULL;
        }
};

Node *input_tree()
{
    Node *root;
    int val;
    cin >> val;

    if(val == -1)
    {
        root = NULL;
        return 0;
    }

    root = new Node(val);
    queue<Node*>q;
    q.push(root);

    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;

        Node *leftNode, *rightNode;

        if(l == -1)
        {
            leftNode = NULL;
        }
        else
        {
            leftNode = new Node(l);
        }

        if(r == -1)
        {
            rightNode = NULL;
        }
        else
        {
            rightNode = new Node(r);
        }

        p->left = leftNode;
        p->right = rightNode;

        if(p->left)
        {
            q.push(p->left);
        }

        if(p->right)
        {
            q.push(p->right);
        }
    }
    return root;
}

void insert(Node *&root, int x)
{
    if(root == NULL)
    {
        root = new Node(x);
    }

    if(root->val > x)
    {
        if(root->left == NULL)
        {
            root->left = new Node(x);
        }
        else
        {
            insert(root->left, x);
        }
    }
    else
    {
        if(root->right == NULL)
        {
            root->right = new Node(x);
        }
        else
        {
            insert(root->right, x);
        }
    }
}

void print_level_order(Node *root)
{
    queue<Node*>q;
    q.push(root);

    while (!q.empty())
    {
        Node *f = q.front();
        q.pop();

        cout << f->val << " ";

        if(f->left)
        {
            q.push(f->left);
        }

        if(f->right)
        {
            q.push(f->right);
        }
    }
    
}

int main()
{
    Node *root = input_tree();
    int val;
    cin >> val;
    insert(root, val);
    print_level_order(root);
    return 0;
}
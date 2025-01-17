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
    int val;
    cin >> val;
    Node *root;

    if(val == -1)
    {
        root = NULL;
        return 0;
    }
    root = new Node(val);
    queue<Node*>q;
    if(root) 
    {
        q.push(root);
    }

    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();

        int l,r;
        cin >> l >> r;

        Node *leftNode;
        Node *rightNode;

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

void print_level_order(Node *root)
{
    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();

        cout << p->val << " ";

        if(p->left)
        {
            q.push(p->left);
        }

        if(p->right)
        {
            q.push(p->right);
        }
    }
}

int main()
{
    Node *root = input_tree();
    print_level_order(root);

    return 0;
}
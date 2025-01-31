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

int sumWithoutLeaf(Node *root)
{
    if(root == NULL)
    {
        return 0;
    }

    queue<Node*> q;
    q.push(root);
    int sum = 0;

    while(!q.empty())
    {
        Node *n = q.front();
        q.pop();

        if(n->left || n->right)
        {
            sum+=n->val;
        }

        if(n->left)
        {
            q.push(n->left);
        }

        if(n->right)
        {
            q.push(n->right);
        }
    }

    return sum;
}

int main()
{
    Node *root = input_tree();
    cout << sumWithoutLeaf(root) << endl;
}
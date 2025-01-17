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
    }

    queue<Node*>q;
    root = new Node(val);
    q.push(root);

    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();

        Node *leftNode, *rightNode;

        int l, r;
        cin >> l >> r;

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

int count_leaf_nodes(Node *root)
{
    if(root == NULL)
    {
        return 0;
    }

    if(root->left == NULL && root->right == NULL)
    {
        return 1;
    }

    int l = count_leaf_nodes(root->left); 
    int r = count_leaf_nodes(root->right);

    return l+r;
}

int main()
{
    Node *root = input_tree();
    cout << count_leaf_nodes(root) << endl;

    return 0;
}   
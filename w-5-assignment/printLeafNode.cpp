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
        return root;
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

void leafNodes(Node *root, vector<int>&v)
{

    if(root == NULL)
    {
        return;
    }

    if(root->left == NULL && root->right == NULL)
    {
        v.push_back(root->val);
        return;
    }

    leafNodes(root->left, v); 
    leafNodes(root->right, v);    
}

void printLeafNode(Node *root)
{
    vector<int> ln;
    leafNodes(root, ln);
    sort(ln.rbegin(), ln.rend());

    for (int val:ln)
    {
        cout << val << " ";
    }
}

int main()
{
    Node *root = input_tree();

    printLeafNode(root);
    cout << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node *left;
        Node *rigth;

        Node(int val)
        {
            this->val = val;
            this->left = NULL;
            this->rigth = NULL;
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

    root = new Node(val);
    queue<Node*>q;
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
        p->rigth = rightNode;

        if(p->left)
        {
            q.push(p->left);
        }

        if(p->rigth)
        {
            q.push(p->rigth);
        }
    }
    return root;
}

int countMaxHeight(Node *root)
{
    if(root == NULL)
    {
        return 0;
    }

    if(root->left == NULL && root->rigth == NULL)
    {
        return 0;
    }

    int l = countMaxHeight(root->left);
    int r = countMaxHeight(root->rigth);

    return max(l,r)+1;
}

int main()
{
    Node *root = input_tree();
    cout << countMaxHeight(root) << endl;

    return 0;
}
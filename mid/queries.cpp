#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node *prev;
        Node *next;

        Node(int val)
        {
            this->val = val;
            this->prev = NULL;
            this->next = NULL;
        }
};

void insert_at_head(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);

    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insert_at_tail(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if(tail ==  NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

bool insert_at_any_pos(Node *&head, Node *&tail, int x, int val)
{
    Node *temp = head;
    Node *newNode = new Node(val);

    int count  = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    if(x < 0 || x > count)
    {
        cout << "Invalid" << endl;
        return false;
    }

    if(x == count)
    {
        insert_at_tail(head, tail, val);
        return true;
    }

    x-=1;
    temp = head;
    while (x--)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if(temp->next != NULL)
    {
        temp->next->prev = newNode;
    }
    temp->next = newNode;

    return true;
}

void print_list_left(Node *head)
{
    Node *temp = head;
    cout << "L -> ";
    while (temp!=NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}
void print_list_right(Node *tail)
{
    Node *temp = tail;
    cout << "R -> ";
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int x, v;
        cin >> x >> v;
        if(x == 0)
        {
            insert_at_head(head, tail, v);
        }
        else if(!insert_at_any_pos(head, tail, x, v))
        {
            continue;
        }
        
        if(head!=NULL)
        {
            print_list_left(head);
            print_list_right(tail);
        }
    
    }
    

    return 0;
}
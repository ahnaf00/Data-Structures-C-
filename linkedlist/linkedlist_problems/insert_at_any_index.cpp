#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* next;

        Node(int val)
        {
            this->val = val;
            this->next = NULL;
        }
};

void insert_at_any_pos(Node* &head, int indx, int val)
{
    Node* newNode = new Node(val);

    if(indx == 0)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    int index = indx - 1;
    Node* temp = head;

    while (index--)
    {
        if(temp->next == NULL)
        {
            cout << "Invalid" << endl;
            delete newNode;
            return;
        }
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void print_list(Node* head)
{
    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    Node* head = NULL;
    int val;
    int pos;
    while (true)
    {
        cin >> pos >> val;
        if(val == -1 && pos == -1)
        {
            break;
        }

        insert_at_any_pos(head, pos, val);
        print_list(head);
    }
    

    return 0;
}
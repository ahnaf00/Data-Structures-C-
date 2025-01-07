#include <bits/stdc++.h>
#include <string>
using namespace std;

class Node{
    public:
        string str;
        Node *prev;
        Node *next;

        Node(string str)
        {
            this->str = str;
            this->prev = NULL;
            this->next = NULL;
        }
};
void insert_at_tail(Node *&head, Node *&tail, string s)
{
    Node* newNode = new Node(s);
    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = tail->next;
    tail->next = newNode;
    tail = newNode;
}

void print_list(Node *head)
{
    Node *temp = head;
    while (temp!=NULL)
    {
        cout << temp->str << " ";
        temp = temp->next;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    string s;
    while (true)
    {
        cin >> s;
        if(s == "end")
        {
            break;
        }
        insert_at_tail(head, tail, s);
    }

    int q;
    cin >> q;

    for (int i = 0; i < 12; i++)
    {
        
    }
    
    
    // print_list(head);
    

    return 0;
}   
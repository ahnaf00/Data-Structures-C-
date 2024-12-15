#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node *next;

        Node(int val){
            this->val = val;
            this->next = NULL;
        }
};


int main()
{   
    Node a(11), b(12), c(13);

    a.next = &b;
    b.next = &c;

    cout << a.val << endl;
    cout << (a.next)->val << endl;
    cout << a.next->next->val << endl;
}
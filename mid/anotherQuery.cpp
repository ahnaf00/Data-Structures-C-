#include <bits/stdc++.h>
using namespace std;

void print_list(list<int> &myList)
{
    cout << "L -> ";
    for (int val : myList)
    {
        cout << val << " ";
    }

    cout << endl;
}

void print_list_right(list<int> &myList)
{
    list<int>tempList(myList);
    tempList.reverse();
    cout << "R -> ";
    for(int val : tempList)
    {
        cout << val << " ";
    }

    cout << endl;
}

int main()
{
    list<int>myList;

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int x,v;
        cin >> x >> v;
        if(x == 0)
        {
            myList.push_front(v);
        }
        else if(x == 1)
        {
            myList.push_back(v);
        }
        else if (x == 2)
        {
            if (v < 0 || v >= myList.size())
            {
                print_list(myList);
                print_list_right(myList);
                continue;
                
            }
            auto it = myList.begin();
            advance(it, v);
            myList.erase(it);
        }

        print_list(myList);
        print_list_right(myList);
    }
    

    return 0;
}   
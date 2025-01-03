#include <bits/stdc++.h>
using namespace std;

int main()
{
    // list<int> l(10, 3);
    list<int> l = {10, 20, 30, 40, 50, 60, 70};
    list<int> l2 = {100, 200};
    vector<int> v = {1,2,3};


    /*
    
    for (auto it = l.begin(); it != l.end(); it++)
    {
        cout << *it << endl;
    }

    */

    // cout << *next(l.begin(), 2) << endl;

    // l.insert(next(l.begin(), 1), v.begin(), v.end());
    // l.erase(next(l.begin(), 2), next(l.begin(), 6));
    // replace(l.begin(), l.end(), 20, 100);

    auto it = find(l.begin(), l.end(), 20);
    if(it == l.end())
    {
        cout << "Not Found" << endl;
    }
    else
    {
        cout << "Found" << endl;
    }

    for (int val : l)
    {
        cout << val << endl;
    }
    
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<int> l = {1,2,3,4,5,6,7,2,1,2,3};

    l.sort();
    // l.sort(greater<int>());

    l.unique();

    for(int val : l)
    {
        cout << val << endl; 
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    set<char> printchars(s.begin(), s.end());

    for (char c : printchars) {
        cout << c;
    }
    return 0;
}
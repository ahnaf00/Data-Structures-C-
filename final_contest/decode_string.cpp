#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin >> tc;

    while (tc--)
    {
        string s,s2="";
        cin >> s;

        for (int i = 0; i < s.length(); i+=2)
        {
            char c = s[i];
            int num = s[i+1] - '0';

            s2.append(num,c);
        }
        cout << s2 << endl;
    }
    

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++)
    {
        string s;
        getline(cin, s);

        map<string, int> count;
        stringstream ss(s);
        string word;

        string freq;
        int mxCount = 0;

        while (ss >> word)
        {
            count[word]++;
            if(count[word] > mxCount)
            {
                mxCount = count[word];
                freq = word;
            }
        }

        cout << freq << " " << mxCount << endl;
    }
    

    return 0;
}
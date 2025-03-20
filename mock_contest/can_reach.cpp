// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long int 
// int target;
// vector<int> dp;

// bool canreach(int initital)
// {
//     if(initital > target)
//     {
//         return false;
//     }

//     if(initital == target)
//     {
//         return true;
//     }

//     if(dp[initital] != -1)
//     {
//         return dp[initital];
//     }

//     return (dp[initital] = canreach(initital+3) || canreach(initital+4));
// }


// int main()
// {
//     cin >> target;
    
//     if (target < 3) {
//         cout << "NO" << endl;
//         return 0;
//     }

//     dp.assign(target+1,-1);

//     int initial = 0;

//     if(canreach(initial))
//     {
//         cout << "YES" << endl;
//     }
//     else
//     {
//         cout << "NO" << endl;
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

#define ll long long int 

int main()
{
    int target;
    cin >> target;

    if (target < 3) {
        cout << "NO" << endl;
        return 0;
    }

    vector<int> dp(target + 1, 0);

    dp[0] = 1; 

    for (int i = 0; i <= target; i++) {
        if (dp[i] == 1) {
            if (i + 3 <= target) dp[i + 3] = 1;
            if (i + 4 <= target) dp[i + 4] = 1;
        }
    }

    if (dp[target] == 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

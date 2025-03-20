#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    sort(nums.begin(),nums.end());

    auto it = unique(nums.begin(),nums.end());

    nums.erase(it,nums.end());

    int sum = 0;

    for(auto c : nums)
    {
        sum+=c;
    }

    cout << sum << endl;
    

    return 0;
}
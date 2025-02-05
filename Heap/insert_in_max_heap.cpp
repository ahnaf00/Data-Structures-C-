#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int val;
    cin >> val;

    arr.push_back(val);

    int cur_indx = arr.size()-1;
    while (cur_indx!=0)
    {
        int parent_indx = (cur_indx-1)/2;
        if(arr[parent_indx] < arr[cur_indx])
        {
            swap(arr[parent_indx] , arr[cur_indx]);
        }
        else
        {
            break;
        }
        cur_indx = parent_indx;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
    
    

    return 0;
}
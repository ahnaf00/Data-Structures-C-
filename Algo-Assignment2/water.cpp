/*
#include <bits/stdc++.h>
using namespace std;

void findMaxWater(vector<int>& height, int n) {
    int max1 = 0, max2 = 0;
    int idx1 = -1, idx2 = -1;

    for (int i = 0; i < n; i++) {
        if (height[i] > max1) {
            max1 = height[i];
            idx1 = i;
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (height[i] > max2 && i != idx1) {
            max2 = height[i];
            idx2 = i;
        }
    }
    
    if (idx1 < idx2) {
        cout << idx1 << " " << idx2 << endl;
    } else {
        cout << idx2 << " " << idx1 << endl;
    }
}

int main() {
    int tc;
    cin >> tc;
    
    while (tc--) {
        int n;
        cin >> n;
        vector<int> water(n);
        
        for (int i = 0; i < n; i++) {
            cin >> water[i];
        }
        
        findMaxWater(water, n);
    }
    
    return 0;
}

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    
    while (tc--) {
        int n;
        cin >> n;
        vector<int> h(n);
        
        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }
        
        int idx1 = 0;
        for (int i = 1; i < n; i++) {
            if (h[i] > h[idx1]) {
                idx1 = i;
            }
        }
        
        int idx2 = (idx1 == 0) ? 1 : 0;
        for (int i = 0; i < n; i++) {
            if (i != idx1 && h[i] > h[idx2]) {
                idx2 = i;
            }
        }
        
        if (idx1 < idx2) {
            cout << idx1 << " " << idx2 << endl;
        } else {
            cout << idx2 << " " << idx1 << endl;
        }
    }
    
    return 0;
}
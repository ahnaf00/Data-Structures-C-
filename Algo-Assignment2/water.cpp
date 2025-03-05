#include <bits/stdc++.h>
using namespace std;

void findMaxWater(vector<int>& height, int n) {
    int left = 0, right = n - 1;
    int maxWater = 0;
    int idx1 = 0, idx2 = 0;

    while (left < right) {
        int h = min(height[left], height[right]);
        int width = right - left;
        int area = h * width;

        if (area > maxWater) {
            maxWater = area;
            idx1 = left;
            idx2 = right;
        }

        if (height[left] < height[right])
            left++;
        else
            right--;
    }

    cout << idx1 << " " << idx2 << endl;
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

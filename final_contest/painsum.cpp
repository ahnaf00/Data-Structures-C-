#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main() {
    ll n, q;
    cin >> n >> q;

    vector<ll> arr_sum(n + 1, 0);

    for (ll i = 1; i <= n; i++) {
        arr_sum[i] = arr_sum[i - 1] + ((i + 2) / 3);
    }

    while (q--) {
        ll l, r;
        cin >> l >> r;
        cout << arr_sum[r] - arr_sum[l - 1] << endl;
    }

    return 0;
}

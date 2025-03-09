#include <bits/stdc++.h>
using namespace std;

void printNums(int n) {
    if (n < 10) {  
        cout << n;
        return;
    }

    printNums(n / 10);
    cout << " " << n % 10;
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;
    
        printNums(n);
        cout << endl;
    }

    return 0;
}

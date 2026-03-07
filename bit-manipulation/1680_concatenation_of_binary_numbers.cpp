#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD = 1e9 + 7;
        long long res = 0;
        int bitLength = 0;

        for(int i = 1; i <= n; i++) {
            if((i & (i - 1)) == 0)
                bitLength++;

            res = ((res << bitLength) | i) % MOD;
        }

        return (int)res;
    }
};

int main() {
    Solution sol;
    int n;

    cout << "--- Concatenated Binary Calculator ---" << endl;
    cout << "Enter a positive integer n: ";
    
    if (!(cin >> n) || n < 0) {
        cout << "Invalid input. Please enter a non-negative integer." << endl;
        return 1;
    }

    int result = sol.concatenatedBinary(n);
    
    cout << "The concatenated binary result for n = " << n << " is: " << result << endl;

    return 0;
}

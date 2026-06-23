#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        if (m <= 0 || n <= 0) return 0;
        if (n == 1) return m; 
        vector<long long> up(m, 1), down(m, 1);

        for (int len = 2; len <= n; len++) {
            vector<long long> newUp(m, 0);
            vector<long long> newDown(m, 0);

            vector<long long> prefix(m + 1, 0);
            for (int i = 0; i < m; i++) {
                prefix[i + 1] = (prefix[i] + up[i]) % MOD;
            }
            for (int y = 0; y < m; y++) {
                newDown[y] = prefix[y];
            }

            vector<long long> suffix(m + 1, 0);
            for (int i = m - 1; i >= 0; i--) {
                suffix[i] = (suffix[i + 1] + down[i]) % MOD;
            }
            for (int y = 0; y < m; y++) {
                newUp[y] = suffix[y + 1];
            }

            up = move(newUp);
            down = move(newDown);
        }

        long long ans = 0;
        for (int i = 0; i < m; i++) {
            ans = (ans + up[i] + down[i]) % MOD;
        }

        return (int)ans;
    }
};

int main() {
    Solution solver;
    int n1 = 2, l1 = 1, r1 = 3;
    cout << "Test Case 1 (n=" << n1 << ", l=" << l1 << ", r=" << r1 << "): ";
    cout << solver.zigZagArrays(n1, l1, r1) << " (Expected: 6)" << endl;


    int n2 = 3, l2 = 1, r2 = 3;
    cout << "Test Case 2 (n=" << n2 << ", l=" << l2 << ", r=" << r2 << "): ";
    cout << solver.zigZagArrays(n2, l2, r2) << " (Expected: 4)" << endl;

    return 0;
}

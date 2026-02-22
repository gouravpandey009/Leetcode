#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int binaryGap(int n) {
        int lastPos = -1;
        int idx = 0;
        int ans = 0;

        while(n > 0) {
            if(n & 1) {
                if(lastPos != -1) {
                    ans = max(ans, idx - lastPos);
                }
                lastPos = idx;
            }
            idx++;
            n >>= 1;
        }

        return ans;
    }
};


int main() {
    Solution sol;

    int n1 = 22;
    int n2 = 8; 
    int n3 = 5;

    cout << "Binary Gap of " << n1 << ": " << sol.binaryGap(n1) << endl;
    cout << "Binary Gap of " << n2 << ": " << sol.binaryGap(n2) << endl;
    cout << "Binary Gap of " << n3 << ": " << sol.binaryGap(n3) << endl;

    return 0;
}

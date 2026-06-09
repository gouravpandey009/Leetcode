#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {

        int mn = INT_MAX;
        int mx = INT_MIN;

        for (int x : nums) {
            mn = min(mn, x);
            mx = max(mx, x);
        }

        return 1LL * (mx - mn) * k;
    }
};

int main() {

    vector<int> nums = {4, 2, 5, 1};
    int k = 3;

    Solution obj;

    cout << obj.maxTotalValue(nums, k) << endl;

    return 0;
}
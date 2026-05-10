#include <bits/stdc++.h>
using namespace std;

int maximumJumps(vector<int>& nums, int target) {

    int n = nums.size();

    vector<int> dp(n, -1);

    dp[0] = 0;

    for (int i = 1; i < n; i++) {

        for (int j = 0; j < i; j++) {

            if (dp[j] != -1 &&
                abs(nums[i] - nums[j]) <= target) {

                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return dp[n - 1];
}

int main() {

    vector<int> nums = {1, 3, 6, 4, 1, 2};
    int target = 2;

    cout << maximumJumps(nums, target);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int maxRotateFunction(vector<int>& nums) {
    long sum = 0, f = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        sum += nums[i];
        f += (long)i * nums[i];
    }

    long ans = f;

    for (int i = n - 1; i > 0; i--) {
        f = f + sum - (long)n * nums[i];
        ans = max(ans, f);
    }

    return ans;
}

int main() {
    vector<int> nums = {4, 3, 2, 6};
    cout << maxRotateFunction(nums) << endl;
    return 0;
}
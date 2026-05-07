#include <bits/stdc++.h>
using namespace std;

vector<int> maxValue(vector<int>& nums) {
    int n = nums.size();

    vector<int> prefixMax(n), suffixMin(n);

    prefixMax[0] = nums[0];

    for (int i = 1; i < n; i++) {
        prefixMax[i] = max(prefixMax[i - 1], nums[i]);
    }

    suffixMin[n - 1] = nums[n - 1];

    for (int i = n - 2; i >= 0; i--) {
        suffixMin[i] = min(suffixMin[i + 1], nums[i]);
    }

    vector<int> ans(n);

    int start = 0;

    for (int i = 0; i < n - 1; i++) {

        if (prefixMax[i] <= suffixMin[i + 1]) {

            int mx = nums[start];

            for (int j = start; j <= i; j++) {
                mx = max(mx, nums[j]);
            }

            for (int j = start; j <= i; j++) {
                ans[j] = mx;
            }

            start = i + 1;
        }
    }

    int mx = nums[start];

    for (int j = start; j < n; j++) {
        mx = max(mx, nums[j]);
    }

    for (int j = start; j < n; j++) {
        ans[j] = mx;
    }

    return ans;
}

int main() {

    vector<int> nums = {2, 3, 1};

    vector<int> ans = maxValue(nums);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}
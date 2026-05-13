#include <bits/stdc++.h>
using namespace std;

int minMoves(vector<int>& nums, int limit) {

    int n = nums.size();

    vector<int> diff(2 * limit + 2, 0);

    for (int i = 0; i < n / 2; i++) {

        int a = nums[i];
        int b = nums[n - 1 - i];

        int x = min(a, b);
        int y = max(a, b);

        diff[2] += 2;

        diff[x + 1] -= 1;

        diff[x + y] -= 1;

        diff[x + y + 1] += 1;

        diff[y + limit + 1] += 1;
    }

    int ans = INT_MAX;
    int current = 0;

    for (int sum = 2; sum <= 2 * limit; sum++) {

        current += diff[sum];

        ans = min(ans, current);
    }

    return ans;
}

int main() {

    vector<int> nums = {1, 2, 4, 3};
    int limit = 4;

    cout << minMoves(nums, limit);

    return 0;
}
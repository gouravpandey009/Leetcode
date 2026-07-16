class Solution {
public:
    long long gcdSum(vector<int>& nums) {

        int n = nums.size();
        vector<int> prefixGcd(n);

        int mx = 0;

        for (int i = 0; i < n; i++) {

            // Current prefix maximum.
            mx = max(mx, nums[i]);

            // gcd(nums[i], prefix maximum).
            prefixGcd[i] = gcd(nums[i], mx);
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        long long ans = 0;

        int l = 0;
        int r = n - 1;

        // Pair smallest with largest.
        while (l < r) {
            ans += gcd(prefixGcd[l], prefixGcd[r]);
            l++;
            r--;
        }

        return ans;
    }
};
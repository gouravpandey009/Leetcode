class Solution {
    const int mod = 1e9 + 7;
    // dp[index][gcd1][gcd2]
    int dp[200][201][201];

public:
    int solve(int i, vector<int> &nums, int first, int second) {
        // Base case: reached the end of the array
        if (i == nums.size()) {
            // Both subsets must be non-empty (GCD > 0) and have equal GCDs
            return (first > 0 && second > 0 && first == second) ? 1 : 0;
        }

        if (dp[i][first][second] != -1) return dp[i][first][second];

        // Option 1: Skip the current element entirely
        int skip = solve(i + 1, nums, first, second);
        
        // Option 2: Include the current element into the first subsequence
        int take1 = solve(i + 1, nums, std::gcd(first, nums[i]), second);

        // Option 3: Include the current element into the second subsequence
        int take2 = solve(i + 1, nums, first, std::gcd(second, nums[i]));
        
        // Sum up all valid ways and store in DP table
        return dp[i][first][second] = (0LL + skip + take1 + take2) % mod;
    }

    int subsequencePairCount(vector<int>& nums) {
        // Initialize the DP array with -1
        memset(dp, -1, sizeof(dp));
        return solve(0, nums, 0, 0);
    }
};

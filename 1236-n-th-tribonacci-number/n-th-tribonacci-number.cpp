class Solution {
public:

    // DP array to store already computed Tribonacci values
    vector<int> dp;

    int solve(int n) {

        // Base cases
        if (n == 0)
            return 0;

        if (n == 1 || n == 2)
            return 1;

        // If already computed, return directly
        if (dp[n] != -1)
            return dp[n];

        // Compute once and store the answer
        dp[n] = solve(n - 1)
              + solve(n - 2)
              + solve(n - 3);

        return dp[n];
    }

    int tribonacci(int n) {

        // Initialize DP array with -1 (meaning not computed yet)
        dp.assign(n + 1, -1);

        return solve(n);
    }
};
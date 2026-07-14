class Solution {
public:
    static constexpr int MAX = 200;
    static constexpr int MOD = 1000000007;

    int subsequencePairCount(vector<int>& nums) {

        static int dp[MAX + 1][MAX + 1];
        static int ndp[MAX + 1][MAX + 1];

        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;

        for (int x : nums) {

            memset(ndp, 0, sizeof(ndp));

            for (int g1 = 0; g1 <= MAX; g1++) {
                for (int g2 = 0; g2 <= MAX; g2++) {

                    int cur = dp[g1][g2];
                    if (!cur) continue;

                    // Don't use x.
                    ndp[g1][g2] += cur;
                    if (ndp[g1][g2] >= MOD)
                        ndp[g1][g2] -= MOD;

                    // Put x into seq1.
                    int ng1 = (g1 == 0 ? x : std::gcd(g1, x));

                    ndp[ng1][g2] += cur;
                    if (ndp[ng1][g2] >= MOD)
                        ndp[ng1][g2] -= MOD;

                    // Put x into seq2.
                    int ng2 = (g2 == 0 ? x : std::gcd(g2, x));

                    ndp[g1][ng2] += cur;
                    if (ndp[g1][ng2] >= MOD)
                        ndp[g1][ng2] -= MOD;
                }
            }

            memcpy(dp, ndp, sizeof(dp));
        }

        long long ans = 0;

        for (int g = 1; g <= MAX; g++) {
            ans += dp[g][g];
        }

        return ans % MOD;
    }
};
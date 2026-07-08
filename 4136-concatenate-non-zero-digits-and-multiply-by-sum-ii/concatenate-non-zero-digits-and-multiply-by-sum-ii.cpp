class Solution {
public:
    static constexpr int MOD = 1000000007;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        // Prefix sum of digits
        vector<int> prefSum(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefSum[i + 1] = prefSum[i] + (s[i] - '0');

        // Non-zero digits and their positions
        vector<int> pos;
        vector<int> prefHash;
        pos.reserve(n);
        prefHash.reserve(n + 1);

        prefHash.push_back(0);

        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                pos.push_back(i);
                prefHash.push_back((10LL * prefHash.back() + (s[i] - '0')) % MOD);
            }
        }

        int m = pos.size();

        // powers of 10
        vector<int> pw(m + 1, 1);
        for (int i = 1; i <= m; i++)
            pw[i] = 10LL * pw[i - 1] % MOD;

        // leftId[i] = first non-zero digit id >= i
        vector<int> leftId(n, -1);
        int p = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            while (p >= 0 && pos[p] >= i) p--;
            leftId[i] = (p + 1 < m) ? p + 1 : -1;
        }

        // rightId[i] = last non-zero digit id <= i
        vector<int> rightId(n, -1);
        p = 0;
        for (int i = 0; i < n; i++) {
            while (p < m && pos[p] <= i) p++;
            rightId[i] = p - 1;
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            int sum = prefSum[r + 1] - prefSum[l];

            int L = leftId[l];
            int R = rightId[r];

            if (L == -1 || R == -1 || L > R) {
                ans.push_back(0);
                continue;
            }

            long long val =
                (prefHash[R + 1] -
                 1LL * prefHash[L] * pw[R - L + 1]) % MOD;

            if (val < 0) val += MOD;

            ans.push_back(val * sum % MOD);
        }

        return ans;
    }
};
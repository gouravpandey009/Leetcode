class Solution {
public:
    static constexpr int MOD = 1000000007;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        const int n = s.size();

        vector<int> prefSum(n + 1);

        for (int i = 0; i < n; i++)
            prefSum[i + 1] = prefSum[i] + (s[i] - '0');

        vector<int> id(n, -1);

        int m = 0;
        for (char c : s)
            if (c != '0')
                m++;

        vector<int> hash(m + 1);
        vector<int> pw(m + 1);

        pw[0] = 1;

        int k = 0;

        for (int i = 0; i < n; i++) {

            if (s[i] == '0')
                continue;

            id[i] = k;

            hash[k + 1] = (10LL * hash[k] + (s[i] - '0')) % MOD;

            pw[k + 1] = (10LL * pw[k]) % MOD;

            k++;
        }

        vector<int> nextId(n);
        vector<int> prevId(n);

        int cur = -1;

        for (int i = n - 1; i >= 0; i--) {

            if (id[i] != -1)
                cur = id[i];

            nextId[i] = cur;
        }

        cur = -1;

        for (int i = 0; i < n; i++) {

            if (id[i] != -1)
                cur = id[i];

            prevId[i] = cur;
        }

        vector<int> ans(queries.size());

        for (int i = 0; i < (int)queries.size(); i++) {

            int l = queries[i][0];
            int r = queries[i][1];

            int L = nextId[l];
            int R = prevId[r];

            if (L == -1 || R == -1 || L > R) {
                ans[i] = 0;
                continue;
            }

            int sum = prefSum[r + 1] - prefSum[l];

            long long val =
                hash[R + 1] -
                1LL * hash[L] * pw[R - L + 1] % MOD;

            if (val < 0)
                val += MOD;

            ans[i] = val * sum % MOD;
        }

        return ans;
    }
};
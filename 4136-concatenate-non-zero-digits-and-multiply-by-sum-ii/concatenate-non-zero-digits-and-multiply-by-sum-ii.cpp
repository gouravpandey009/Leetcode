class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        int n = s.size();

        vector<int> prefSum(n + 1, 0);

        for (int i = 0; i < n; i++)
            prefSum[i + 1] = prefSum[i] + (s[i] - '0');

        vector<int> pos, digit;
        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                pos.push_back(i);
                digit.push_back(s[i] - '0');
            }
        }

        int m = digit.size();

        vector<long long> pw(m + 1, 1);
        for (int i = 1; i <= m; i++)
            pw[i] = pw[i - 1] * 10 % MOD;

        vector<long long> pref(m + 1, 0);
        for (int i = 0; i < m; i++)
            pref[i + 1] = (pref[i] * 10 + digit[i]) % MOD;

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            long long sum = prefSum[r + 1] - prefSum[l];

            auto it1 = lower_bound(pos.begin(), pos.end(), l);
            auto it2 = upper_bound(pos.begin(), pos.end(), r);

            if (it1 == it2) {
                ans.push_back(0);
                continue;
            }

            int L = it1 - pos.begin();
            int R = int(it2 - pos.begin()) - 1;
            int len = R - L + 1;

            long long val = (pref[R + 1] - pref[L] * pw[len]) % MOD;
            if (val < 0) val += MOD;

            ans.push_back(val * sum % MOD);
        }

        return ans;
    }
};
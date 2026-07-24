class Solution {
    map<vector<int>, int> dp;

    int dfs(vector<int>& cnt, int left) {
        if (dp.count(cnt)) return dp[cnt];

        int res = 0, bz = cnt.size();
        for (int j = 1; j < bz; ++j) {
            if (cnt[j] > 0) {
                --cnt[j];
                res = max(res, (left == 0) + dfs(cnt, (bz + left - j) % bz));
                ++cnt[j];
            }
        }
        return dp[cnt] = res;
    }

public:
    int maxHappyGroups(int batchSize, vector<int>& groups) {
        vector<int> cnt(batchSize, 0);
        int res = 0;

        for (int group : groups) {
            int rem = group % batchSize;
            if (rem == 0) {
                res++;
            } else if (cnt[batchSize - rem] > 0) {
                cnt[batchSize - rem]--;
                res++;
            } else {
                cnt[rem]++;
            }
        }

        return res + dfs(cnt, 0);
    }
};
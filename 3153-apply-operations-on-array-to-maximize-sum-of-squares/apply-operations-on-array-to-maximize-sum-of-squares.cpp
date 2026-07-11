class Solution {
public:
        int maxSum(vector<int>& A, int k) {
        vector<int> count(32);
        for (int a : A)
            for (int i = 0; i < 32; i++)
                if (a & (1 << i))
                    count[i]++;
        int res = 0, mod = 1e9 + 7;
        for (int j = 0; j < k; j++) {
            int cur = 0;
            for (int i = 0; i < 32; i++) {
                if (count[i] > 0) {
                    count[i]--;
                    cur += 1 << i;
                }
            }
            res = (res + 1L * cur * cur % mod) % mod;
        }
        return res;
    }
};
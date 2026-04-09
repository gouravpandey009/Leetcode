#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int mod = 1e9 + 7;

    long long power(long long base, long long exp) {
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp & 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return res;
    }

    long long modInv(long long n) {
        return power(n, mod - 2);
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int limit = sqrt(n);

        map<int, vector<vector<int>>> lightK;

        for (auto& q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];

            if (k >= limit) {
                // Brute force for large k
                for (int i = l; i <= r; i += k) {
                    nums[i] = (1LL * nums[i] * v) % mod;
                }
            } else {
                lightK[k].push_back(q);
            }
        }

        for (auto const& it : lightK) {
            int k = it.first;
            const vector<vector<int>>& query_list = it.second;

            vector<long long> diff(n, 1);

            for (auto& q : query_list) {
                int l = q[0], r = q[1], v = q[3];
                diff[l] = (diff[l] * v) % mod;

                int steps = (r - l) / k;
                int next = l + (steps + 1) * k;

                if (next < n) {
                    diff[next] = (diff[next] * modInv(v)) % mod;
                }
            }

            for (int i = 0; i < n; i++) {
                if (i >= k) {
                    diff[i] = (diff[i] * diff[i - k]) % mod;
                }
                nums[i] = (1LL * nums[i] * diff[i]) % mod;
            }
        }

        long long final_xor = 0;
        for (int x : nums) final_xor ^= x;

        return (int)final_xor;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 3, 1, 5, 4};
    vector<vector<int>> queries = {
        {1, 4, 2, 3},
        {0, 2, 1, 2}
    };

    cout << sol.xorAfterQueries(nums, queries) << endl;
    return 0;
}

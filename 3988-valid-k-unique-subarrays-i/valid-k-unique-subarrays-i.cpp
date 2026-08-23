#include <vector>
#include <unordered_map>
#include <random>
#include <algorithm>
#include <cstdint>

using namespace std;

class BIT {
    int n;
    vector<int> tree;
public:
    BIT(int n) : n(n), tree(n + 1, 0) {}

    void add(int i, int delta) {
        for (; i <= n; i += i & -i) tree[i] += delta;
    }

    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i) sum += tree[i];
        return sum;
    }

    int queryRange(int l, int r) {
        return query(r) - query(l - 1);
    }
};

class Solution {
public:
    vector<bool> validSubarrays(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();

        // 1. Zobrist Hash Prefix XOR (Guarantees even frequencies if XOR == 0)
        mt19937_64 rng(1337);
        unordered_map<int, uint64_t> val_to_hash;
        for (int x : nums) {
            if (val_to_hash.find(x) == val_to_hash.end()) {
                val_to_hash[x] = rng();
            }
        }

        vector<uint64_t> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] ^ val_to_hash[nums[i]];
        }

        vector<bool> ans(q, false);

        // Group queries by right endpoint `r` for Offline BIT processing
        struct QueryInfo { int l, id; };
        vector<vector<QueryInfo>> queries_at_r(n);

        for (int i = 0; i < q; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int len = r - l + 1;

            // Pre-filter invalid conditions
            if (len % 2 == 0 && len >= 2 * k && (pref[r + 1] ^ pref[l]) == 0) {
                queries_at_r[r].push_back({l, i});
            }
        }

        // 2. Count distinct elements in range [l, r] in O(log N) using BIT
        BIT bit(n);
        unordered_map<int, int> last_pos;

        for (int r = 0; r < n; r++) {
            int val = nums[r];
            if (last_pos.count(val)) {
                bit.add(last_pos[val] + 1, -1); // Remove previous instance
            }
            bit.add(r + 1, 1); // Add current instance
            last_pos[val] = r;

            // Answer queries ending at index r
            for (const auto& query : queries_at_r[r]) {
                int distinct = bit.queryRange(query.l + 1, r + 1);
                if (distinct == k) {
                    ans[query.id] = true;
                }
            }
        }

        return ans;
    }
};
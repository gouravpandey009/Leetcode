class Solution {
public:
    vector<bool> validSubarrays(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();
        int block = sqrt(n);
        int ql = queries.size();

        // Store queries as {left, right, original_index}
        vector<array<int, 3>> iqueries(ql);
        for (int i = 0; i < ql; i++) {
            iqueries[i] = {queries[i][0], queries[i][1], i};
        }

        // Sort queries using Mo's ordering
        sort(iqueries.begin(), iqueries.end(), [block](const array<int, 3>& a, const array<int, 3>& b) {
            int blockA = a[0] / block;
            int blockB = b[0] / block;
            if (blockA != blockB) {
                return blockA < blockB;
            }
            return a[1] < b[1];
        });

        vector<bool> ans(ql, false);
        int L = 0;
        int R = -1;

        int distinct = 0;
        int odd = 0;
        int maxElement = *max_element(nums.begin(), nums.end());
        vector<int> frequencies(maxElement + 1, 0);

        for (const auto& iQ : iqueries) {
            int l = iQ[0];
            int r = iQ[1];
            int index = iQ[2];

            // Expand left
            while (L > l) {
                L--;
                frequencies[nums[L]]++;
                if (frequencies[nums[L]] == 1) distinct++;
                if (frequencies[nums[L]] % 2 == 1) odd++;
                else odd--;
            }

            // Expand right
            while (R < r) {
                R++;
                frequencies[nums[R]]++;
                if (frequencies[nums[R]] == 1) distinct++;
                if (frequencies[nums[R]] % 2 == 1) odd++;
                else odd--;
            }

            // Shrink left
            while (L < l) {
                frequencies[nums[L]]--;
                if (frequencies[nums[L]] == 0) distinct--;
                if (frequencies[nums[L]] % 2 == 0) odd--;
                else odd++;
                L++;
            }

            // Shrink right
            while (R > r) {
                frequencies[nums[R]]--;
                if (frequencies[nums[R]] % 2 == 1) odd++;
                else odd--;
                if (frequencies[nums[R]] == 0) distinct--;
                R--;
            }

            if (distinct == k && odd == 0) {
                ans[index] = true;
            }
        }

        return ans;
    }
};
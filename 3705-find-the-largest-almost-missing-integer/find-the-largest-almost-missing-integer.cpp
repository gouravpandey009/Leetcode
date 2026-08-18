class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> count;

        for (int i = 0; i + k <= nums.size(); ++i) {
            unordered_set<int> seen;

            for (int j = i; j < i + k; ++j)
                seen.insert(nums[j]);

            for (int x : seen)
                ++count[x];
        }

        int ans = -1;

        for (auto [x, cnt] : count) {
            if (cnt == 1)
                ans = max(ans, x);
        }

        return ans;
    }
};
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        int mn = INT_MAX;
        int mx = INT_MIN;

        unordered_set<int> seen;

        for (int x : nums) {

            mn = min(mn, x);
            mx = max(mx, x);

            seen.insert(x);
        }

        vector<int> ans;

        // Check every value inside the original range.
        for (int x = mn + 1; x < mx; x++) {

            if (!seen.count(x))
                ans.push_back(x);
        }

        return ans;
    }
};
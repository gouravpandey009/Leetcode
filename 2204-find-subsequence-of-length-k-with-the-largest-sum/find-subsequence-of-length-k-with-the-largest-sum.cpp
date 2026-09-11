class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> v;

        // Value ke saath original index store karo
        for (int i = 0; i < nums.size(); i++) {
            v.push_back({nums[i], i});
        }

        // Largest values first
        sort(v.rbegin(), v.rend());

        // Sirf top k elements rakho
        v.resize(k);

        // Original order mein sort karo
        sort(v.begin(), v.end(), [](auto a, auto b) {
            return a.second < b.second;
        });

        vector<int> ans;

        // Final answer banao
        for (auto p : v) {
            ans.push_back(p.first);
        }

        return ans;
    }
};
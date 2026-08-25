class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st(nums.begin(), nums.end());

        for (int i = 1; ; ++i) {
            int x = k * i;

            if (!st.count(x))
                return x;
        }
    }
};

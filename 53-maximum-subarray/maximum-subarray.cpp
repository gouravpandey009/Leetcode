class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN;
        int current_prefix = 0;
        int min_prefix = 0;
        
        for (int num : nums) {
            current_prefix += num;
            max_sum = max(max_sum, current_prefix - min_prefix);
            min_prefix = min(min_prefix, current_prefix);
        }
        
        return max_sum;
    }
};

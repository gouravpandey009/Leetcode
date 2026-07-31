class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN;
        int window_sum = 0;
        
        for (int num : nums) {
            window_sum += num;
            max_sum = max(max_sum, window_sum);
            
            if (window_sum < 0) {
                window_sum = 0;
            }
        }
        
        return max_sum;
    }
};

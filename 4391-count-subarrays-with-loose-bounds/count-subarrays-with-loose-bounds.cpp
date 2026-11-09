class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int temp = 0;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            if(nums[i] >= minK && nums[i] <= maxK){
                ans += (i - temp + 1);
            } else {
                temp = i + 1;
            }
        }

        return ans;
    }
};
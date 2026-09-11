class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int sum = 0;
        int ans = nums.size() + 1;

        for(int right = 0 ; right < nums.size() ; right++){
            sum += nums[right];


            while(sum >= target){
                ans = min(ans , right - left + 1);\
                

                sum -= nums[left];
                left++;
            }
        }

        if(ans == nums.size() + 1)
        return 0;

        return ans;
    } 
};
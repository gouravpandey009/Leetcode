class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 1;
        int maxLen = 1;
        if(n == 1) return 1;
        long long sum = nums[0];
        int rem = nums[0]%k;
        while(i < n && j < n){
            if(nums[j]%k != rem){
                sum = nums[j];
                i = j;
                rem = nums[j] % k;
                j++;
                continue;
            }

            sum += nums[j];
            if(sum % k == rem) maxLen = max(maxLen , j - i + 1);
            j++;
        }

        return maxLen;
    }
};
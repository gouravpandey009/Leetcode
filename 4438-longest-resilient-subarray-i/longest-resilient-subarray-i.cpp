class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen = 1;
        for(int i = 0 ; i < n ; i++){
            int r = nums[i] % k;
            int sum = nums[i];
            for(int j = i + 1; j < n ; j++){
                if(nums[j]%k != r) break;
                long long len = j - i + 1;
                sum += nums[j];
                if((sum%k) == r) maxLen = max(maxLen, (int)len);
            }
        }
        return maxLen;
    }
};
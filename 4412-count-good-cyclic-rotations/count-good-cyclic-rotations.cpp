class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        long long total = 0;
        for(int x : nums){
            total += x;
        }

        int len = n / 2;
        long long first = 0;
        for(int i = 0 ; i < len ; i++){
            first += nums[i];
        }

        int cnt = 0;

        for(int start = 0 ; start < n ; start++){
            if(first > total - first){
                cnt++;
            }

            first -= nums[start];
            first += nums[(start + len) % n];
        }

        return cnt;
    }
};
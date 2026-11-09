class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        vector<int> rev;
        long long ans = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            ans += nums[i];
            int num = nums[i];
            vector<int> digit;
            while(num){
                digit.push_back(num % 10);
                num /= 10;
            }

            sort(begin(digit) , end(digit));
            long long large = 0;
            for(int j = digit.size() - 1 ; j >= 0 ; j--){
                large = 1LL * large * 10 + digit[j];
            }

            if(nums[i] < large){
                int gain = large - nums[i];
                rev.push_back(gain);
            }
        }

        sort(begin(rev) , end(rev));
        for(int i = rev.size()  - 1 ; i >= 0 && k != 0 ; i--){
            ans += rev[i];
            k--;
        }

        return ans;
    }
};
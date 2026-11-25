class Solution {
public:
    int minOperations(vector<int>& nums, int sum) {
        int n = nums.size();
        vector<int>dp(sum + 1 , INT_MAX);
        dp[0] = 0;
        for(int i = 0 ;i < n ; i++){
            int val = nums[i];
            vector<pair<int, int>>curr;
            long long x = val;
            int count = 0;
            while(x <= sum){
                curr.push_back({x , count});
                 x *= 2;
                 count++;
            }

            x = val;
            count = 0;
            while(x > 1){
                x /= 2;
                count++;

                if(x <= sum){
                    curr.push_back({x , count});
                }
            }

            vector<int>next = dp;
            for(int j = 0 ; j <= sum; j++){
                if(dp[j] == INT_MAX){
                    continue;
                }

                for(auto p : curr){
                    int x = p.first;
                    int count = p.second;

                    if(j + x <= sum){
                        next[j + x] = min(next[j + x] , dp[j] + count);
                    }
                }
            }

            dp = next;
        }

        return dp[sum] == INT_MAX ? -1 : dp[sum];
    }
};
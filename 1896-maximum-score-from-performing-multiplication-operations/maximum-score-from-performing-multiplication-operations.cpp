class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& mult) {
        const int N = nums.size() , M = mult.size();
        vector<vector<int>> dp(M + 1 , vector<int>(M + 1  , 0));
        for(int i = M - 1 ; i >= 0 ; --i){
            for(int j = M - 1 - i ; j >= 0 ; --j){
                const int depth = i + j;
                dp[i][j] = max(dp[i + 1][j] + nums[i] * mult[depth] , dp[i][j + 1] + nums[N - 1 - j] * mult[depth]);
            }
        }

        return dp[0][0];
    }
};
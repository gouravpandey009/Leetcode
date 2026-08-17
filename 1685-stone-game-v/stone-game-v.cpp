class Solution {
public:
    int dp[501][501];
    int rec(int low ,int high , vector<int>& pref){
        if(high == low)return 0;
        if(dp[low][high] != -1){
            return dp[low][high];
        }

        int ans = 0;
        for(int i = low ; i < high ; i++){
            int left = pref[i + 1] - pref[low];
            int right = pref[high + 1] - pref[i + 1];
            if(left < right){
                ans = max(ans , left + rec(low , i ,pref));
            }

            else if(left > right){
                ans = max(ans , right + rec(i + 1 , high , pref));
            }

            else {
                ans = max(ans , max(left + rec(low , i , pref) ,right + rec(i + 1 , high ,pref)));
            }
        }

        return dp[low][high] = ans;
    }


    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        memset(dp , -1 ,sizeof(dp));
        vector<int>pref(n + 1);
        for(int i = 0 ; i < n ; i++){
            pref[i + 1] = pref[i] + stoneValue[i];
        }
        return rec(0 ,n - 1, pref);
    }
};
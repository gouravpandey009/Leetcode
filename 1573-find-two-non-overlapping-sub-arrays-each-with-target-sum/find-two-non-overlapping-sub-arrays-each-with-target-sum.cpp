class Solution {
public:
    int n;
    vector<vector<int>>dp;
    vector<int> nxt;

    int solve(int i , int k){
        if(k == 0) return 0;
        if(i >= n) return 1e9;
        if(dp[i][k] != -1) return dp[i][k];
        int ans = solve(i + 1 , k);
        if(nxt[i] != -1){
            int len = nxt[i] - i + 1;
            int rest = solve(nxt[i] + 1 , k - 1);
            if(rest != 1e9)ans = min(ans , len + rest);
        }
        return dp[i][k] = ans;
    }
    int minSumOfLengths(vector<int>& arr, int target) {
        n = arr.size();
        dp.resize(n , vector<int>(3 , -1));
        nxt.resize(n , -1);
        int l = 0 , curr = 0;
        for(int r = 0 ; r < n ; r++){
            curr += arr[r];
            while(curr > target){
                curr -= arr[l];
                l++;
            }

            if(curr == target)nxt[l] = r;
        }

        int ans = solve(0 , 2);
        return ans == 1e9 ? -1 : ans;

    }
};
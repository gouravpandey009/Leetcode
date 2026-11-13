class Solution {
public:

    vector<bool>track = vector<bool>(15 ,true);
    void solve(vector<int>& nums , int s , int e , int bit){
        if(bit < 0 || s > e) return;

        int j = s;
        if(track[bit] == 1){
            for(int i = s ; i <= e ; i++){
                if((nums[i] >> bit) & 1) swap(nums[i] , nums[j++]);
                else track[bit] = 0; 
            }
        }

        solve(nums , s , j - 1 , bit - 1);
        for(int b = bit - 1 ; b >= 0 ; b--)
        if(track[b] == 1) solve(nums , j , e,b);
    }


    vector<int> largestPower(vector<int>& nums) {
        int n = nums.size();
        solve(nums , 0 , n - 1 , 14);
        vector<int> ans(15 ,0);
        for(int i = 0 ; i < 15 ; i++){
            int j = 0 ;
            int bit = 14 - i;
            while(j < n && (nums[j] >> bit)&1)j++;
            ans[i] = j;
        }

        return ans;
    }
};
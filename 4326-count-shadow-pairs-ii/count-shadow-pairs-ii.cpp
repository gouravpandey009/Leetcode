class Solution {

    vector<int>vals , temp , sidx , lidx;

    long long solve(int left , int right , int lval , int hval){
        if(right - left <= 1 || hval - lval <= 1)
        return 0;

        int midValue = lval + (hval - lval) / 2;
        int smallTop = 0 , largeTop = 0;
        int smallCount = 0;
        long long ans = 0;

        for(int i = left ; i < right ; ++i){
            if(vals[i] < midValue){
                while(smallTop > 0 && vals[sidx[smallTop - 1]] < vals[i]){
                    smallTop--;
                }

                sidx[smallTop++] = i;
                smallCount++;
            }

            else {
                while(largeTop > 0 && vals[lidx[largeTop - 1]] >= vals[i]){
                    largeTop--;
                }

                int blockerIdx = (largeTop > 0) ? lidx[largeTop - 1] : left - 1;
                int smallFirstValid = upper_bound(sidx.begin() , sidx.begin() + smallTop , blockerIdx) - sidx.begin();

                ans += (smallTop - smallFirstValid);
                lidx[largeTop++] = i;
            }
        }

        int p = left , q = left + smallCount;
        for(int i = left ; i < right ; ++i){
            if(vals[i] < midValue) temp[p++] = vals[i];
            else temp[q++] = vals[i];
        }

        copy(temp.begin() + left , temp.begin() + right , vals.begin() + left);
        ans += solve(left , left + smallCount , lval , midValue);
        ans += solve(left + smallCount , right , midValue , hval);

        return ans;
    }


public:
    int shadowPairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> us = nums;
        sort(us.begin() , us.end());
        us.erase(unique(us.begin() , us.end()) , us.end());
        
        vals.resize(n);
        temp.resize(n);
        sidx.resize(n);
        lidx.resize(n);

        for(int i = 0 ; i < n ; i++){
            vals[i] = lower_bound(us.begin() , us.end() , nums[i]) - us.begin();
        }

        return solve(0 , n , 0 , us.size());
    }
};
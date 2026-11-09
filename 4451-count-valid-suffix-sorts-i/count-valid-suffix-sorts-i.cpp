class Solution {
public:
    int countSuffix(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        int ans = 0;
        int i = 0;
        int maxi = nums[n - 1];

        for(i = 0 ; i < n ; i++){
            if(nums[i] == target[i]) continue;
            ans++;
            break;
        }

        for(int j = i ; j < n; j++){
            maxi = max(nums[j] , maxi);
        }

        i--;
        

        while(i >= 0 && nums[i] >= maxi && target[i] == nums[i]){
            ans++;
            maxi = max(maxi , nums[i]);
            i--;
        }

        i++;
        sort(nums.begin() + i , nums.end());
        reverse(nums.begin() + i , nums.end());

        if(nums == target) return ans;
        return 0;
    }
};
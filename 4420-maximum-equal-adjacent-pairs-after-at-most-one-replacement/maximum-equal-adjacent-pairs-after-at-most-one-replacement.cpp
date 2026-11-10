class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int base = 0 , gain = 0;
        unordered_map<long long , int> cnt;
        for(int i = 1 ; i < nums.size() ; i++){
            int a = min(nums[i - 1] , nums[i]) , b = max(nums[i - 1] , nums[i]);
            if(a == b) base++;
            else gain = max(gain , ++cnt[(long long)a << 32 | b]);
        }
        return base + gain;
    }
};
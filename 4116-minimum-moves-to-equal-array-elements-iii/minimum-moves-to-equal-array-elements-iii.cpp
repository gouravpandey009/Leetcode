class Solution {
public:
    int minMoves(vector<int>& nums) {
        long long n = nums.size();
        long long mx = *max_element(nums.begin() , nums.end());
        long long sum = accumulate(nums.begin() , nums.end() , 0LL);
        return n * mx - sum;
    }
};
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        

        unordered_set<int> seen;


        for(int number : nums)
            seen.insert(number);

            for(int number = 0 ; number <= nums.size() ; number++){
                if(!seen.count(number))
                return number;
            }
                
        return -1;
    }
};
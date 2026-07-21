class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_set<int>  seen;

        for(int number : nums){
            if(seen.count(number))

            return true;

            seen.insert(number);
        }

        return false;
    }
};
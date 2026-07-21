class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        unordered_set<int> seen;

        for (int number : nums) {

            // Duplicate found
            if (seen.count(number))
                return true;

            // Store current number
            seen.insert(number);
        }

        return false;
    }
};
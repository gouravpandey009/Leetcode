class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        vector<int> temp;

        // Store all non-zero elements
        for (int num : nums) {
            if (num != 0)
                temp.push_back(num);
        }

        // Add zeroes
        while (temp.size() < nums.size())
            temp.push_back(0);

        // Copy back
        nums = temp;
    }
};
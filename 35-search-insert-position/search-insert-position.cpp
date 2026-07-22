class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        // Traverse every element one by one
        for (int i = 0; i < nums.size(); i++) {

            // First element greater than or equal to target
            // is the required position.
            if (nums[i] >= target)
                return i;
        }

        // Target is greater than every element,
        // so insert at the end.
        return nums.size();
    }
};
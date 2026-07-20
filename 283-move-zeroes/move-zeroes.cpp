class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        // Position where the next non-zero element should be placed
        int write = 0;

        // Scan the entire array
        for (int read = 0; read < nums.size(); read++) {

            // Found a non-zero element
            if (nums[read] != 0) {

                // Move it to its correct position
                swap(nums[write], nums[read]);

                // Next position for a non-zero
                write++;
            }
        }
    }
};
class Solution {
public:
    int findMin(vector<int>& nums) {

        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {

            int mid = left + (right - left) / 2;

            // Minimum right side mein hai
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            }

            // Minimum mid ya left side mein hai
            else {
                right = mid;
            }
        }

        // left == right
        return nums[left];
    }
};
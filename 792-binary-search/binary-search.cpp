class Solution {
public:
    int search(vector<int>& nums, int target) {

        int left = 0;
        int right = (nums.size()) - 1;

        while (left <= right) {

            // Overflow-safe middle index.
            int mid = left + (right - left) / 2;

            // Target found.
            if (nums[mid] == target) {
                return mid;
            }

            // Target can only exist in the right half.
            if (nums[mid] < target) {
                left = mid + 1;
            }

            // Target can only exist in the left half.
            else {
                right = mid - 1;
            }
        }

        // Search space became empty.
        return -1;
    }
};
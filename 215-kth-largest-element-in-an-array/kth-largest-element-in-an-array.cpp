class Solution {
public:

    // Performs 3-way partitioning around the pivot.
    //
    // After partitioning:
    //
    // [left ... low-1]      -> elements < pivot
    // [low  ... high]       -> elements == pivot
    // [high+1 ... right]    -> elements > pivot
    //
    // Returns the range [low, high] containing
    // all elements equal to the pivot.
    pair<int, int> partition3Way(
        vector<int>& nums,
        int left,
        int right,
        int pivot
    ) {
        int low = left;
        int mid = left;
        int high = right;

        while (mid <= high) {

            // Current element is smaller than pivot.
            if (nums[mid] < pivot) {

                swap(nums[low], nums[mid]);

                low++;
                mid++;
            }

            // Current element is equal to pivot.
            else if (nums[mid] == pivot) {

                // It is already in the correct middle region.
                mid++;
            }

            // Current element is greater than pivot.
            else {

                swap(nums[mid], nums[high]);

                high--;

                // Do NOT increment mid.
                // The newly swapped element still needs processing.
            }
        }

        // [low ... high] contains all elements equal to pivot.
        return {low, high};
    }


    int findKthLargest(vector<int>& nums, int k) {

        int left = 0;
        int right = nums.size() - 1;

        // Convert kth largest into its equivalent
        // index in ascending sorted order.
        int targetIndex = nums.size() - k;

        while (left <= right) {

            // Choose a pivot from the current search space.
            //
            // Using the middle element gives us a better
            // deterministic choice than always using right.
            int middle = left + (right - left) / 2;
            int pivot = nums[middle];

            // Perform 3-way partitioning.
            auto [equalStart, equalEnd] =
                partition3Way(nums, left, right, pivot);

            // Target lies inside the region containing
            // elements equal to the pivot.
            if (targetIndex >= equalStart &&
                targetIndex <= equalEnd) {

                return nums[targetIndex];
            }

            // Target lies in the smaller-than-pivot region.
            if (targetIndex < equalStart) {

                right = equalStart - 1;
            }

            // Target lies in the greater-than-pivot region.
            else {

                left = equalEnd + 1;
            }
        }

        return -1;
    }
};
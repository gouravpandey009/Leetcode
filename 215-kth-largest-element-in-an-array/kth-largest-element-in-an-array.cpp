class Solution {
public:

    /*
        3-Way Partition

        After partitioning:

        [left ... equalStart-1]
            -> elements smaller than pivot

        [equalStart ... equalEnd]
            -> elements equal to pivot

        [equalEnd+1 ... right]
            -> elements greater than pivot
    */
    pair<int, int> partition3Way(
        vector<int>& nums,
        int left,
        int right,
        int pivot
    ) {

        // 'low' marks where the next element
        // smaller than pivot should go.
        int low = left;

        // 'mid' scans the unknown region.
        int mid = left;

        // 'high' marks where the next element
        // greater than pivot should go.
        int high = right;

        while (mid <= high) {

            // ------------------------------------------------
            // Case 1: Current element is smaller than pivot
            // ------------------------------------------------
            if (nums[mid] < pivot) {

                // Move the smaller element to the left region.
                swap(nums[low], nums[mid]);

                // Left region grows.
                low++;

                // The swapped element is processed,
                // so move to the next unknown element.
                mid++;
            }

            // ------------------------------------------------
            // Case 2: Current element equals pivot
            // ------------------------------------------------
            else if (nums[mid] == pivot) {

                // It already belongs to the middle region.
                mid++;
            }

            // ------------------------------------------------
            // Case 3: Current element is greater than pivot
            // ------------------------------------------------
            else {

                // Move the greater element to the right region.
                swap(nums[mid], nums[high]);

                // Right region grows.
                high--;

                // IMPORTANT:
                // Do NOT increment mid.
                //
                // The element that came from 'high'
                // has not been processed yet.
            }
        }

        // All elements from low to high are equal to pivot.
        return {low, high};
    }


    int findKthLargest(vector<int>& nums, int k) {

        int n = nums.size();

        // Convert kth largest into its equivalent
        // index in ascending sorted order.
        //
        // Example:
        //
        // [1,2,3,4,5,6]
        // 2nd largest = 5
        //
        // Index = n - k
        //       = 6 - 2
        //       = 4
        int targetIndex = n - k;

        // Current Quickselect search range.
        int left = 0;
        int right = n - 1;

        while (left <= right) {

            // Choose the middle element as the pivot.
            //
            // This is better than always choosing
            // the last element because it avoids
            // one obvious source of bad partitions.
            int pivotIndex = left + (right - left) / 2;

            int pivot = nums[pivotIndex];

            // Partition the current range into:
            //
            // < pivot
            // == pivot
            // > pivot
            auto [equalStart, equalEnd] =
                partition3Way(nums, left, right, pivot);


            // ------------------------------------------------
            // Target lies inside the equal-to-pivot region.
            // ------------------------------------------------
            if (targetIndex >= equalStart &&
                targetIndex <= equalEnd) {

                return nums[targetIndex];
            }


            // ------------------------------------------------
            // Target lies in the smaller-than-pivot region.
            // ------------------------------------------------
            if (targetIndex < equalStart) {

                right = equalStart - 1;
            }

            // ------------------------------------------------
            // Target lies in the greater-than-pivot region.
            // ------------------------------------------------
            else {

                left = equalEnd + 1;
            }
        }

        // This line is theoretically unreachable because
        // the problem guarantees a valid k.
        return -1;
    }
};
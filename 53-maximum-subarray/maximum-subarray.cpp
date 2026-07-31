class Solution {
public:

    // ------------------------------------------------------------
    // Function to calculate the maximum subarray sum
    // that crosses the middle element.
    // ------------------------------------------------------------
    int crossingSum(vector<int>& nums, int left, int mid, int right) {

        // ---------------- Left Part ----------------

        // Stores the maximum sum ending at mid.
        int leftMax = INT_MIN;

        // Running sum while moving towards left.
        int currentSum = 0;

        // Start from mid and move towards left.
        for (int i = mid; i >= left; i--) {

            currentSum += nums[i];

            // Update the best left sum.
            leftMax = max(leftMax, currentSum);
        }


        // ---------------- Right Part ----------------

        // Stores the maximum sum starting from mid + 1.
        int rightMax = INT_MIN;

        currentSum = 0;

        // Start from mid + 1 and move towards right.
        for (int i = mid + 1; i <= right; i++) {

            currentSum += nums[i];

            // Update the best right sum.
            rightMax = max(rightMax, currentSum);
        }

        // Crossing subarray =
        // Best Left Ending at Mid
        // +
        // Best Right Starting at Mid+1
        return leftMax + rightMax;
    }

    // ------------------------------------------------------------
    // Divide & Conquer Recursive Function
    // ------------------------------------------------------------
    int solve(vector<int>& nums, int left, int right) {

        // Base Case:
        // Only one element remains.
        if (left == right)
            return nums[left];

        // Find middle element.
        int mid = left + (right - left) / 2;

        // Maximum subarray completely inside left half.
        int leftAnswer = solve(nums, left, mid);

        // Maximum subarray completely inside right half.
        int rightAnswer = solve(nums, mid + 1, right);

        // Maximum subarray crossing the middle.
        int crossingAnswer = crossingSum(nums, left, mid, right);

        // Return the best among all three possibilities.
        return max({leftAnswer, rightAnswer, crossingAnswer});
    }

    int maxSubArray(vector<int>& nums) {

        // Start Divide & Conquer on the complete array.
        return solve(nums, 0, nums.size() - 1);
    }
};
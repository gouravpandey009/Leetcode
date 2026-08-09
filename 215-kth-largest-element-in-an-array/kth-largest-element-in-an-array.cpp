class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        // Sort the array in ascending order.
        sort(nums.begin(), nums.end());

        // The kth largest element is
        // at index n - k.
        return nums[nums.size() - k];
    }
};
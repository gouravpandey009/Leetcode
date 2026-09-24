class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right){
            int mid = left + (right - left) /2;

            //if target found
            if(nums[mid] == target)
            return mid;

            //left half sorted

            if(nums[left] <= nums[mid]){
                if(nums[left] <= target && target <= nums[mid])
                right = mid - 1;

                else 
                left = mid + 1;
            }

            //right half sorted 
            else{
                if(nums[mid] <= target && target <= nums[right])
                left = mid + 1;

                else 
                right = mid - 1;

            }
        }
        return -1;
    }
};
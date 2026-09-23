class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size() - 1;

        while(left <= right){
            //middle postion
            int mid = left + (right - left) / 2;

            //target right side

            if(nums[mid] < target){
                left = mid + 1;
            }

            else{
                right = mid - 1;
            }
        }

        return left;
        
    }
};
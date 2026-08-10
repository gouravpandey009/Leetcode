class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int uniqueIndex = 0;

        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i] != nums[uniqueIndex]){
                uniqueIndex++;

                nums[uniqueIndex] = nums[i];
            }
        }

        return uniqueIndex + 1;
    }
};
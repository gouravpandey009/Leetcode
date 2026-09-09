class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {

        // Sort the array
        sort(nums.begin(), nums.end());

        //  for loop for converting  - numbers to +
        for (int i = 0; i < nums.size() && k > 0; i++) 
        {

            // if the number is negative, flip k
            if (nums[i] < 0) 
            {
                nums[i] = -nums[i];
                k--;
            }

        }

        // again  sort the array again
        sort(nums.begin(), nums.end());

        // if k is odd, flip the smallest number
        if (k % 2 == 1) {
            nums[0] = -nums[0];
        }

        // int the sum
        int sum = 0;

        // again for loop
        for (int i = 0; i < nums.size(); i++) 
        {
            sum += nums[i];
        }

        // return the maximum sum
        return sum;
    }

};
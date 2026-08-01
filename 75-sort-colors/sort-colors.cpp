class Solution {
public:
    void sortColors(vector<int>& nums) {

        int count0 = 0;
        int count1 = 0;
        int count2 = 0;


        for(int num : nums){
            if(num == 0)
            count0++;

            else if(num == 1)
            count1++;

            else 
            count2++;
        }

        int index = 0;

        while(count0--)
        nums[index++] = 0;

        while(count1--)
        nums[index++] = 1;

        while(count2--)
        nums[index++] = 2;       
    }
};
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();

        for(int number = 0 ;  number <= n ; number++){
            bool found = false;


            for(int value : nums){
                if(value == number){
                    found  = true;

                    break;
                }
            }

            if(!found)
            return number;
        }

        return -1;
    }
};
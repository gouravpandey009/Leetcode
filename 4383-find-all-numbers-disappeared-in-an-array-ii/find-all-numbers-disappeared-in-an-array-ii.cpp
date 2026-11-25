class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<int> range(upper - lower + 1 , 1);
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] < lower || nums[i] > upper)
            continue;
            range[nums[i] - lower] = 0;
        }

        vector<vector<int>>ans;
        int start = -1;
        for(int i = lower ; i <= upper ; i++){
            if(range[i - lower] == 1){
                if(start == -1){
                    start = i;
                }
            }

            else{
                if(start != -1){
                    ans.push_back({start , i - 1});
                }

                start = -1;
            }
        }

        if(start != -1){
            ans.push_back({start , upper});
        }

        return ans;
    }
};
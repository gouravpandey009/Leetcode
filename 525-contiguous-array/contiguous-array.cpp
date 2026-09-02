class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        unordered_map<int, int> firstIndex;
        
        int sum = 0;

        int maxLen = 0;

        firstIndex[0] = -1;

        for(int i = 0 ; i < nums.size() ; i++){
            
            if(nums[i] == 0){
                sum--;
            } else {
                sum++;
            }

            if(firstIndex.count(sum)){
                int length = i - firstIndex[sum];

                maxLen = max(maxLen , length);
            }

            else {
                firstIndex[sum] = i;
            }
        }

        return maxLen;
    }
};
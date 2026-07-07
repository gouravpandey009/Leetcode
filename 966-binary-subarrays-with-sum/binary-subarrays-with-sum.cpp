class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        vector<int>temp;
        int counter = 0;
        for(int i : nums){
            if(i == 0) counter++;
            else{
                temp.push_back(counter) ;
                counter = 0;
            }

        }

            temp.push_back(counter);
            int sum = 0;
            int l , r;
            for(l = 0 , r = l + goal ; r < temp.size() ; l++ , r++){
                if(l == r) sum += (temp[l] * (temp[l] +1))/2;
                else sum += (temp[l] + 1) * (temp[r] + 1);
            }
            return sum;
        }
};
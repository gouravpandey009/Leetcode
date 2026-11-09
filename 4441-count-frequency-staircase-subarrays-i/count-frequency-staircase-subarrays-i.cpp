class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int ans = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            unordered_map<int , int> fre;
            unordered_map<int , int> pos;
            int k = 1;
            int bad = 0;

            for(int j = i ; j < nums.size() ; j++){
                int x = nums[j];
                if(fre[x] > 0 && fre[x] != pos[x]) bad--;
                if(fre[x] == 0) pos[x] = k++;
                fre[x]++;
                if(fre[x] != pos[x]) bad++;
                if(bad == 0) ans++;
            }
        }

        return ans;
    }
};
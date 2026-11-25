class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int , vector<int>>mp;
        for(int i = 0 ; i < nums.size() ; i++){
            mp[nums[i]].push_back(i);
        }

        int ans = 0;
        for(auto m : mp){
            auto v = m.second;
            bool flag = false;
            for(int i = 1; i < v.size() ; i++){
                if(v[i] - v[i - 1] != 1){
                    flag = true;
                }
            }

            if(!flag) ans++;
        }

            return ans;
        }
};
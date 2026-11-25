class Solution {
public:

    string solve(int n){
        string t;
        int p = 0;
        while(n){
            if(n & 1 and p == 26) t = "zz" + t;
            else if(n & 1) t = (char)(p + 'a') + t;
            n >>= 1;
            p++;
        }

        return t;
    }

    vector<string> largestString(vector<int>& nums) {
        vector<string>ans;
        for(auto x : nums){
            string s = solve(x);
            ans.push_back(s);
        }

        return ans;
    }
};
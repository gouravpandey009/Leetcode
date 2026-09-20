class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;
        for(int i = 0 ; i < s.size() ; i++){
            // rev alphabet
            int revval = 26 - (s[i] - 'a');

            ans += revval * (i + 1);
        }
        return ans;
    }
};
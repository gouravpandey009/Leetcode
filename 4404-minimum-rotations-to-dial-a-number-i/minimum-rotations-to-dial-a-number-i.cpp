class Solution {
public:
    int minRotations(string s) {
        int ans = 0;
        int prev = 0;
        for(auto ch : s){
            int x = ch - '0';
            int diff = abs(x - prev);
            ans += min(diff , 10 - diff);
            prev = x;
        }
        return ans;
    }
};
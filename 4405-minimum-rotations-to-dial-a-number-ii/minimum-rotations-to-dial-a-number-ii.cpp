class Solution {
public:
    int minRotations(int n, string s) {
        int dif = 0;
        int num = 0;
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            int ele1 = max(num , s[i] - '0');
            int ele2 = min(num , s[i] - '0');
            int ele3 = max(num , s[n - 1] - '0');
            int ele4 = min(num , s[n - 1] - '0');
            int r1 = min(abs(ele3 - ele4) , abs((10 - ele3) + ele4));
            int r2 = min(abs(ele1 - ele2) , abs((10 - ele1) + ele2));
            ans += r2;
            if((r2 - r1) > dif){
                dif = r2 - r1;
            }
            num = s[i] - '0';
        }
        return ans - dif;
    }
};
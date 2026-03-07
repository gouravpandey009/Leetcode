#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string s2 = s + s;

        string alt1 = "", alt2 = "";

        for(int i = 0; i < 2*n; i++){
            alt1 += (i % 2 ? '1' : '0');
            alt2 += (i % 2 ? '0' : '1');
        }

        int res = INT_MAX;
        int diff1 = 0, diff2 = 0;
        int l = 0;

        for(int r = 0; r < 2*n; r++){

            if(s2[r] != alt1[r]) diff1++;
            if(s2[r] != alt2[r]) diff2++;

            if(r - l + 1 > n){
                if(s2[l] != alt1[l]) diff1--;
                if(s2[l] != alt2[l]) diff2--;
                l++;
            }

            if(r - l + 1 == n){
                res = min(res, min(diff1, diff2));
            }
        }

        return res;
    }
};

int main(){
    Solution sol;
    cout << sol.minFlips("111000") << endl;
}
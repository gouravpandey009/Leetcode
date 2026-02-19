#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int res = 0;
        int prev = 0;
        int strk = 1;

        for(int i = 1; i < s.size(); i++) {
            if(s[i] == s[i - 1]) {
                strk++;
            } else {
                prev = strk;
                strk = 1;
            }

            if(strk <= prev) res++;
        }

        return res;
    }
};

int main() {
    Solution sol;
    string testInput = "00110011";
    cout << "Result: " << sol.countBinarySubstrings(testInput) << endl;
    return 0;
}

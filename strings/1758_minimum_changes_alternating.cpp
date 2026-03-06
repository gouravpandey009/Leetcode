#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int changeStart0 = 0;
        int changeStart1 = 0;

        for(int i = 0; i < s.size(); i++) {
            char expected0 = (i % 2 == 0) ? '0' : '1';
            char expected1 = (i % 2 == 0) ? '1' : '0';

            if(s[i] != expected0) changeStart0++;
            if(s[i] != expected1) changeStart1++;
        }

        return min(changeStart0, changeStart1);
    }
};

int main() {
    Solution sol;
    cout << sol.minOperations("0100") << endl;
    return 0;
}
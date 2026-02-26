#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSteps(string s) {
        int steps = 0;

        while(s != "1") {
            if(s.back() == '0') {
                // even - divide by 2
                s.pop_back();
            } else {
                // odd - add 1
                int i = s.size() - 1;
                while(i >= 0 && s[i] == '1') {
                    s[i] = '0';
                    i--;
                }
                if(i >= 0) {
                    s[i] = '1';
                } else {
                    s = "1" + s;
                }
            }
            steps++;
        }

        return steps;
    }
};

int main() {
    Solution sol;
    string test1 = "1101";
 
    string test2 = "10";  
    string test3 = "1";  

    cout << "Steps for " << test1 << ": " << sol.numSteps(test1) << endl;
    cout << "Steps for " << test2 << ": " << sol.numSteps(test2) << endl;
    cout << "Steps for " << test3 << ": " << sol.numSteps(test3) << endl;

    return 0;
}



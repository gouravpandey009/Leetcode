#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> seen;

        if (s.size() < (1 << k) + k - 1) return false;

        for(int i = 0; i + k <= s.size(); i++) {
            seen.insert(s.substr(i, k));
        }

        return seen.size() == (1 << k);
    }
};

int main() {
    Solution sol;

    string s1 = "00110110";
    int k1 = 2;
    cout << "Test Case 1: " << (sol.hasAllCodes(s1, k1) ? "true" : "false") << endl;

    string s2 = "0110";
    int k2 = 1;
    cout << "Test Case 2: " << (sol.hasAllCodes(s2, k2) ? "true" : "false") << endl;

    string s3 = "0110";
    int k3 = 2;
    cout << "Test Case 3: " << (sol.hasAllCodes(s3, k3) ? "true" : "false") << endl;

    return 0;
}

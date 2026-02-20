#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> parts;
        int balance = 0;
        int start = 0;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '1') balance++;
            else balance--;

            if(balance == 0) {
                string inside = s.substr(start + 1, i - start - 1);
                parts.push_back("1" + makeLargestSpecial(inside) + "0");
                start = i + 1;
            }
        }

        sort(parts.begin(), parts.end(), greater<string>());

        string res = "";
        for(auto &p : parts) res += p;

        return res;
    }
};



int main() {
    Solution sol;
    string s = "11011000"; // Example special string
    cout << "Result: " << sol.makeLargestSpecial(s) << endl;
    return 0;
}

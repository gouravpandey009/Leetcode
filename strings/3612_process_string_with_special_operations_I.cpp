#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string processStr(string s) {

        string result;

        for (char c : s) {

            if (c >= 'a' && c <= 'z') {
                result.push_back(c);
            }
            else if (c == '*') {
                if (!result.empty())
                    result.pop_back();
            }
            else if (c == '#') {
                result += result;
            }
            else if (c == '%') {
                reverse(result.begin(), result.end());
            }
        }

        return result;
    }
};

int main() {

    Solution obj;

    string s = "a#b%*";

    cout << obj.processStr(s) << endl;

    return 0;
}
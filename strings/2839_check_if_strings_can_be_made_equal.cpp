#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canBeEqual(string s1, string s2) {

        bool g1 = (s1[0] == s2[0] && s1[2] == s2[2]) ||
                  (s1[0] == s2[2] && s1[2] == s2[0]);

        bool g2 = (s1[1] == s2[1] && s1[3] == s2[3]) ||
                  (s1[1] == s2[3] && s1[3] == s2[1]);

        return g1 && g2;
    }
};

int main() {

    string s1, s2;
    cout << "Enter s1 and s2: ";
    cin >> s1 >> s2;

    Solution sol;

    cout << (sol.canBeEqual(s1, s2) ? "True" : "False") << endl;

    return 0;
}
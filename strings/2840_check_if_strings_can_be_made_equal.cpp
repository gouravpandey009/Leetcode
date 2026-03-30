#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkStrings(string s1, string s2) {

        vector<int> even(26, 0), odd(26, 0);

        for(int i = 0; i < s1.size(); i++) {

            if(i % 2 == 0) {
                even[s1[i] - 'a']++;
                even[s2[i] - 'a']--;
            } else {
                odd[s1[i] - 'a']++;
                odd[s2[i] - 'a']--;
            }
        }

        for(int i = 0; i < 26; i++) {
            if(even[i] != 0 || odd[i] != 0)
                return false;
        }

        return true;
    }
};

int main() {

    string s1, s2;
    cout << "Enter s1 and s2: ";
    cin >> s1 >> s2;

    Solution sol;

    cout << (sol.checkStrings(s1, s2) ? "True" : "False") << endl;

    return 0;
}
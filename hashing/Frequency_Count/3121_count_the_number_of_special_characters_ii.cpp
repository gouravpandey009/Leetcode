#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int numberOfSpecialChars(string word) {

        vector<int> lastLower(26, -1);

        vector<int> firstUpper(26, -1);

        int n = word.size();

        for (int i = 0; i < n; i++) {

            char ch = word[i];

            if (islower(ch)) {

                lastLower[ch - 'a'] = i;
            }
            else {

                if (firstUpper[ch - 'A'] == -1) {

                    firstUpper[ch - 'A'] = i;
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < 26; i++) {

            if (lastLower[i] != -1 &&
                firstUpper[i] != -1 &&
                lastLower[i] < firstUpper[i]) {

                ans++;
            }
        }

        return ans;
    }
};

int main() {

    Solution obj;

    string word = "aaAbBc";

    cout << obj.numberOfSpecialChars(word);

    return 0;
}
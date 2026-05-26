#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:

    int numberOfSpecialChars(string word) {

        unordered_set<char> st;

        for (char ch : word) {
            st.insert(ch);
        }

        int ans = 0;

        for (char ch = 'a'; ch <= 'z'; ch++) {

            if (st.count(ch) &&
                st.count(ch - 'a' + 'A')) {

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
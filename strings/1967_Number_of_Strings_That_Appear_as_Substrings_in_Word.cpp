#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {

        int count = 0;

        for (string &pattern : patterns) {

            if (word.find(pattern) != string::npos)
                count++;
        }

        return count;
    }
};

int main() {

    Solution obj;

    vector<string> patterns = {
        "a",
        "abc",
        "bc",
        "d"
    };

    string word = "abc";

    cout << "Answer = "
         << obj.numOfStrings(patterns, word)
         << endl;

    return 0;
}
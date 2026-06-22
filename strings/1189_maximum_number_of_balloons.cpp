#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {

        vector<int> freq(26, 0);

        for (char c : text)
            freq[c - 'a']++;

        return min({
            freq['b' - 'a'],
            freq['a' - 'a'],
            freq['l' - 'a'] / 2,
            freq['o' - 'a'] / 2,
            freq['n' - 'a']
        });
    }
};

int main() {

    string text = "loonbalxballpoon";

    Solution obj;

    cout << obj.maxNumberOfBalloons(text);

    return 0;
}
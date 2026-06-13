#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string mapWordWeights(vector<string>& words,
                          vector<int>& weights) {

        string answer;

        for (const string& word : words) {

            long long sum = 0;

            for (char ch : word) {
                sum += weights[ch - 'a'];
            }

            int rem = sum % 26;

            answer.push_back('z' - rem);
        }

        return answer;
    }
};

int main() {

    vector<string> words = {
        "abcd",
        "def",
        "xyz"
    };

    vector<int> weights = {
        5,3,12,14,1,2,3,2,10,6,6,9,7,
        8,7,10,8,9,6,9,9,8,3,7,7,2
    };

    Solution obj;

    cout << obj.mapWordWeights(words, weights);

    return 0;
}
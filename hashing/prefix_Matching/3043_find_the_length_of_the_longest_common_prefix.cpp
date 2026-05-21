#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        unordered_set<string> prefixes;

        for (int num : arr1) {

            string s = to_string(num);

            string current = "";

            for (char ch : s) {

                current += ch;

                prefixes.insert(current);
            }
        }

        int ans = 0;

        for (int num : arr2) {

            string s = to_string(num);

            string current = "";

            for (int i = 0; i < s.size(); i++) {

                current += s[i];

                if (prefixes.count(current)) {
                    ans = max(ans, i + 1);
                }
            }
        }

        return ans;
    }
};

int main() {

    Solution obj;

    vector<int> arr1 = {1, 10, 100};
    vector<int> arr2 = {1000};

    cout << obj.longestCommonPrefix(arr1, arr2);

    return 0;
}
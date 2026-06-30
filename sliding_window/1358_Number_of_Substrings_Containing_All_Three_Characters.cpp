#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {

        vector<int> freq(3, 0);

        int left = 0;
        int ans = 0;
        int n = s.size();

        for (int right = 0; right < n; right++) {

            freq[s[right] - 'a']++;

            while (freq[0] > 0 &&
                   freq[1] > 0 &&
                   freq[2] > 0) {

                ans += (n - right);

                freq[s[left] - 'a']--;
                left++;
            }
        }

        return ans;
    }
};

int main() {

    Solution obj;

    string s = "abcabc";

    cout << "Answer = "
         << obj.numberOfSubstrings(s)
         << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;

        for (int x : nums)
            freq[x]++;

        long long mx = *max_element(nums.begin(), nums.end());

        int ans = 1;

        // Special case for value = 1
        if (freq.count(1))
            ans = (freq[1] % 2 == 0) ? freq[1] - 1 : freq[1];

        for (auto &[start, cnt] : freq) {

            if (start == 1)
                continue;

            long long cur = start;
            int len = 0;

            while (true) {

                auto it = freq.find(cur);

                if (it == freq.end() || it->second < 2)
                    break;

                len += 2;

                // Prevent overflow while squaring
                if (cur > mx / cur)
                    break;

                cur = cur * cur;
            }

            auto it = freq.find(cur);

            if (it != freq.end() && it->second >= 1)
                len++;
            else
                len--;

            ans = max(ans, len);
        }

        return ans;
    }
};

int main() {

    Solution obj;

    vector<int> nums = {
        48841,358801,28561,18974736,4356,221,358801,
        599,13,4356,66,48841,28561,815730721,
        13,815730721,18974736,66,169,599,169,221
    };

    cout << "Maximum Length = " << obj.maximumLength(nums) << endl;

    return 0;
}
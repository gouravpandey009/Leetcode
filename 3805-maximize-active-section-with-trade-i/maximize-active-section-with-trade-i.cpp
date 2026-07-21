class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {

        int n = s.size();

        int ones = 0;
        int best = 0;

        int prevZero = INT_MIN;

        for (int i = 0; i < n; ) {

            int j = i + 1;

            while (j < n && s[j] == s[i])
                ++j;

            int len = j - i;

            if (s[i] == '1') {

                // Count existing active sections.
                ones += len;

            } else {

                // Merge two neighboring zero blocks.
                best = max(best, prevZero + len);
                prevZero = len;
            }

            i = j;
        }

        return ones + best;
    }
};
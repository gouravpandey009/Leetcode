class Solution {
public:
    string minWindow(string s, string t) {

        int need[128] = {};
        int have[128] = {};

        // t mein har character kitni baar chahiye.
        for (char c : t)
            need[c]++;

        int left = 0;
        int count = 0;

        int start = 0;
        int len = s.size() + 1;

        for (int right = 0; right < s.size(); right++) {

            // Current character window mein add karo.
            char c = s[right];
            have[c]++;

            // Is character ki required frequency complete hui.
            if (have[c] <= need[c])
                count++;

            // Window valid hai, ab chhota karo.
            while (count == t.size()) {

                if (right - left + 1 < len) {
                    len = right - left + 1;
                    start = left;
                }

                // Left character window se remove karo.
                char c = s[left];
                have[c]--;

                // Required character ki frequency toot gayi.
                if (have[c] < need[c])
                    count--;

                left++;
            }
        }

        if (len == s.size() + 1)
            return "";

        return s.substr(start, len);
    }
};
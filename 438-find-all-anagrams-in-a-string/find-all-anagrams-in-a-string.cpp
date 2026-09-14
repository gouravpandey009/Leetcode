class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> ans;

        int pFreq[26] = {};
        int sFreq[26] = {};

        for (char c : p)
            pFreq[c - 'a']++;

        int k = p.size();

        for (int i = 0; i < s.size(); i++) {

            sFreq[s[i] - 'a']++;

            // Window size becomes k.
            if (i >= k)
                sFreq[s[i - k] - 'a']--;

            // Check if both frequencies are same.
            if (i >= k - 1) {

                bool same = true;

                for (int j = 0; j < 26; j++) {
                    if (pFreq[j] != sFreq[j]) {
                        same = false;
                        break;
                    }
                }

                if (same)
                    ans.push_back(i - k + 1);
            }
        }

        return ans;
    }
};
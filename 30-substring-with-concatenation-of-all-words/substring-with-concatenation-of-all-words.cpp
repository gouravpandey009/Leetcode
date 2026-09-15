class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> ans;

        int len = words[0].size();
        int n = words.size();

        unordered_map<string, int> need;

        // Har word kitni baar chahiye.
        for (string word : words)
            need[word]++;

        // Different starting alignments check karo.
        for (int start = 0; start < len; start++) {

            unordered_map<string, int> have;
            int left = start;
            int count = 0;

            // Ek-ek complete word read karo.
            for (int right = start; right + len <= s.size(); right += len) {

                string word = s.substr(right, len);

                // Ye word required hi nahi hai.
                if (!need.count(word)) {
                    have.clear();
                    count = 0;
                    left = right + len;
                    continue;
                }

                // Word window mein add karo.
                have[word]++;
                count++;

                // Word required se zyada aa gaya.
                while (have[word] > need[word]) {
                    string old = s.substr(left, len);
                    have[old]--;
                    left += len;
                    count--;
                }

                // Saare words exactly mil gaye.
                if (count == n) {
                    ans.push_back(left);

                    // Next possible window ke liye left word hatao.
                    string old = s.substr(left, len);
                    have[old]--;
                    left += len;
                    count--;
                }
            }
        }

        return ans;
    }
};
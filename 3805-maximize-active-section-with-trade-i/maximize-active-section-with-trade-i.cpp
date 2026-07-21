class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        string t = "1" + s + "1";
        int n = t.size();

        vector<pair<char,int>> blocks;
        int i = 0;
        while (i < n) {
            char c = t[i];
            int j = i;
            while (j < n && t[j] == c) j++;
            blocks.push_back({c, j - i});
            i = j;
        }

        int ones = count(s.begin(), s.end(), '1');
        int maxGain = 0;

        for (int k = 1; k + 1 < (int)blocks.size(); k++) {
            if (blocks[k].first == '1' &&
                blocks[k-1].first == '0' &&
                blocks[k+1].first == '0') {
                maxGain = max(maxGain, blocks[k-1].second + blocks[k+1].second);
            }
        }

        return ones + maxGain;
    }
};
class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int cnt[26] = {};

        for (char c : s)
            ++cnt[c - 'a'];

        string quinorath = s;

        int n = s.size();
        int i = 0;

        while (i < n && cnt[target[i] - 'a'] > 0) {
            --cnt[target[i] - 'a'];
            ++i;
        }

        while (true) {
            if (i < n) {
                for (int c = target[i] - 'a' + 1; c < 26; ++c) {
                    if (cnt[c] == 0)
                        continue;

                    string ans = target.substr(0, i);
                    ans.push_back('a' + c);

                    --cnt[c];

                    for (int j = 0; j < 26; ++j)
                        ans.append(cnt[j], 'a' + j);

                    return ans;
                }
            }

            if (i == 0)
                break;

            --i;
            ++cnt[target[i] - 'a'];
        }

        return "";
    }
};
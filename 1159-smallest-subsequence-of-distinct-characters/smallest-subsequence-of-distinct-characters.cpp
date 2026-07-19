class Solution {
public:
    string smallestSubsequence(string s) {

        vector<int> freq(26, 0);
        vector<bool> vis(26, false);

        for (char c : s)
            freq[c - 'a']++;

        string st;

        for (char c : s) {

            // One occurrence has been processed.
            freq[c - 'a']--;

            // Already included.
            if (vis[c - 'a'])
                continue;

            // Remove bigger characters if they appear later.
            while (!st.empty() &&
                   st.back() > c &&
                   freq[st.back() - 'a'] > 0) {

                vis[st.back() - 'a'] = false;
                st.pop_back();
            }

            st.push_back(c);
            vis[c - 'a'] = true;
        }

        return st;
    }
};
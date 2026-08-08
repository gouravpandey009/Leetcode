class Solution {
public:
    vector<int> validSequence(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();

        vector<int> last(m, -1);

        // Latest positions that can match each suffix character.
        int i = n - 1;
        int j = m - 1;

        while (i >= 0 && j >= 0) {

            if (word1[i] == word2[j])
                last[j--] = i;

            i--;
        }

        vector<int> ans;
        ans.reserve(m);

        bool usedMismatch = false;
        j = 0;

        for (i = 0; i < n && j < m; i++) {

            if (word1[i] == word2[j]) {

                ans.push_back(i);
                j++;

            } else if (!usedMismatch &&
                       (j == m - 1 || i < last[j + 1])) {

                // Use the only allowed mismatch here.
                ans.push_back(i);
                j++;
                usedMismatch = true;
            }
        }

        return j == m ? ans : vector<int>();
    }
};
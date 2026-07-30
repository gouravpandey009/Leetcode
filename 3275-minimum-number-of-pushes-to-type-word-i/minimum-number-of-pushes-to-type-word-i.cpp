class Solution {
public:
    int minimumPushes(string word) {

        int ans = 0;

        for (int i = 0; i < word.size(); i++) {

            // Every 8 letters require one extra push.
            ans += i / 8 + 1;
        }

        return ans;
    }
};
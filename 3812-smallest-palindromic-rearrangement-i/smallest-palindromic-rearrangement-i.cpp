class Solution {
public:
    string smallestPalindrome(string s) {

        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        string left;
        char mid = 0;

        for (int i = 0; i < 26; i++) {

            // Left half gets half of the occurrences.
            left.append(freq[i] / 2, char('a' + i));

            // Odd frequency character goes to the middle.
            if (freq[i] & 1)
                mid = char('a' + i);
        }

        string right = left;
        reverse(right.begin(), right.end());

        if (mid)
            return left + string(1, mid) + right;

        return left + right;
    }
};
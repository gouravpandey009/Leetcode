class Solution {
private:

    // Returns C(n, r), capped at k + 1.
    long long comb(long long n, long long r, long long k) {

        r = min(r, n - r);

        long long res = 1;

        for (long long i = 1; i <= r; i++) {

            res = res * (n - i + 1) / i;

            if (res > k)
                return k + 1;
        }

        return res;
    }

public:

    string smallestPalindrome(string s, long long k) {

        int half = s.size() / 2;

        vector<int> cnt(26);

        // Only the left half determines the palindrome.
        for (int i = 0; i < half; i++)
            cnt[s[i] - 'a']++;

        auto countWays = [&](int rem) {

            long long ways = 1;

            for (int i = 0; i < 26; i++) {

                if (!cnt[i])
                    continue;

                ways *= comb(rem, cnt[i], k);

                if (ways > k)
                    return k + 1;

                rem -= cnt[i];
            }

            return ways;
        };

        string left;

        long long rank = 1;

        for (int pos = 0; pos < half; pos++) {

            for (int c = 0; c < 26; c++) {

                if (!cnt[c])
                    continue;

                cnt[c]--;

                long long ways = countWays(half - pos - 1);

                if (rank + ways > k) {

                    left += char('a' + c);
                    break;
                }

                cnt[c]++;
                rank += ways;
            }
        }

        if ((int)left.size() != half)
            return "";

        string mid;

        if (s.size() & 1)
            mid += s[half];

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};
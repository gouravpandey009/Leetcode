class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int q1 = 0, q2 = 0;
        int s1 = 0, s2 = 0;

        for (int i = 0; i < n / 2; ++i) {
            if (num[i] == '?')
                ++q1;
            else
                s1 += num[i] - '0';
        }

        for (int i = n / 2; i < n; ++i) {
            if (num[i] == '?')
                ++q2;
            else
                s2 += num[i] - '0';
        }

        if ((q1 + q2) & 1)
            return true;

        return 2 * (s1 - s2) != 9 * (q2 - q1);
    }
};
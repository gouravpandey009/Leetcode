#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dist(int a, int b) {
        if(a == -1) return 0;
        int x1 = a / 6, y1 = a % 6;
        int x2 = b / 6, y2 = b % 6;
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int dp[301][27][27];

    int solve(string &word, int i, int f1, int f2) {
        if(i == word.size()) return 0;

        if(dp[i][f1][f2] != -1) return dp[i][f1][f2];

        int cur = word[i] - 'A';

        int useF1 = dist(f1, cur) + solve(word, i+1, cur, f2);
        int useF2 = dist(f2, cur) + solve(word, i+1, f1, cur);

        return dp[i][f1][f2] = min(useF1, useF2);
    }

    int minimumDistance(string word) {
        memset(dp, -1, sizeof(dp));
        return solve(word, 0, -1, -1);
    }
};

int main() {
    Solution sol;
    cout << sol.minimumDistance("CAKE") << endl;
}
#include <bits/stdc++.h>
using namespace std;

long long maximumScore(vector<vector<int>>& grid) {
    int n = grid.size();

    vector<vector<long long>> pref(n + 1, vector<long long>(n, 0));

    for(int j = 0; j < n; j++) {
        for(int i = 0; i < n; i++) {
            pref[i + 1][j] = pref[i][j] + grid[i][j];
        }
    }

    vector<vector<long long>> dp(n, vector<long long>(n + 1, 0));

    for(int j = 1; j < n; j++) {
        for(int h = 0; h <= n; h++) {
            long long best = 0;

            for(int ph = 0; ph <= n; ph++) {
                long long val = dp[j - 1][ph];

                if(h > ph) {
                    val += pref[h][j - 1] - pref[ph][j - 1];
                }

                best = max(best, val);
            }

            dp[j][h] = best;
        }
    }

    long long ans = 0;
    for(int h = 0; h <= n; h++) {
        ans = max(ans, dp[n - 1][h]);
    }

    return ans;
}

int main() {
    vector<vector<int>> grid = {
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };

    cout << maximumScore(grid) << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int maxScore(vector<vector<int>>& grid, int k) {
    int n = grid.size(), m = grid[0].size();

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k + 1, -1)));

    int cost = (grid[0][0] == 2);
    int score = (grid[0][0] == 1);

    if(cost <= k)
        dp[0][0][cost] = score;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {

            for(int c = 0; c <= k; c++) {

                if(dp[i][j][c] == -1) continue;

                if(j + 1 < m) {
                    int nc = c + (grid[i][j+1] == 2);
                    int ns = dp[i][j][c] + (grid[i][j+1] == 1);

                    if(nc <= k)
                        dp[i][j+1][nc] = max(dp[i][j+1][nc], ns);
                }

                if(i + 1 < n) {
                    int nc = c + (grid[i+1][j] == 2);
                    int ns = dp[i][j][c] + (grid[i+1][j] == 1);

                    if(nc <= k)
                        dp[i+1][j][nc] = max(dp[i+1][j][nc], ns);
                }
            }
        }
    }

    int ans = -1;
    for(int c = 0; c <= k; c++) {
        ans = max(ans, dp[n-1][m-1][c]);
    }

    return ans;
}

int main() {
    vector<vector<int>> grid = {{0,1,2},{1,2,0}};
    int k = 1;

    cout << maxScore(grid, k) << endl;
}
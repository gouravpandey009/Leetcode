class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();

        int total = m * n;
        k %= total;

        vector<vector<int>> ans(m, vector<int>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // Current position in flattened array.
                int idx = i * n + j;

                // Position after shifting.
                int nxt = (idx + k) % total;

                // Convert back to matrix coordinates.
                ans[nxt / n][nxt % n] = grid[i][j];
            }
        }

        return ans;
    }
};
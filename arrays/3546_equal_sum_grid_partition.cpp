#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        long long total = 0;

        for(auto &row : grid)
            for(auto &val : row)
                total += val;

        if(total % 2 != 0) return false;

        long long target = total / 2;

        long long prefix = 0;

        // Horizontal cut
        for(int i = 0; i < m - 1; i++) {
            for(int j = 0; j < n; j++) {
                prefix += grid[i][j];
            }
            if(prefix == target) return true;
        }

        // Column sums
        vector<long long> colSum(n, 0);

        for(int j = 0; j < n; j++) {
            for(int i = 0; i < m; i++) {
                colSum[j] += grid[i][j];
            }
        }

        prefix = 0;

        // Vertical cut
        for(int j = 0; j < n - 1; j++) {
            prefix += colSum[j];
            if(prefix == target) return true;
        }

        return false;
    }
};

int main() {

    int m, n;
    cout << "Enter rows and columns: ";
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));

    cout << "Enter grid:\n";
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];

    Solution sol;

    cout << (sol.canPartitionGrid(grid) ? "True" : "False") << endl;

    return 0;
}
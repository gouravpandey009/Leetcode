#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<long long>> maxDP(m, vector<long long>(n));
        vector<vector<long long>> minDP(m, vector<long long>(n));

        maxDP[0][0] = minDP[0][0] = grid[0][0];

        for(int i = 1; i < m; i++) {
            maxDP[i][0] = minDP[i][0] = maxDP[i-1][0] * grid[i][0];
        }

        for(int j = 1; j < n; j++) {
            maxDP[0][j] = minDP[0][j] = maxDP[0][j-1] * grid[0][j];
        }

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {

                long long a = grid[i][j] * maxDP[i-1][j];
                long long b = grid[i][j] * minDP[i-1][j];
                long long c = grid[i][j] * maxDP[i][j-1];
                long long d = grid[i][j] * minDP[i][j-1];

                maxDP[i][j] = max({a, b, c, d});
                minDP[i][j] = min({a, b, c, d});
            }
        }

        long long ans = maxDP[m-1][n-1];
        if(ans < 0) return -1;

        return ans % 1000000007;
    }
};

int main() {
    int m, n;
    cout << "Enter rows and columns: ";
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));

    cout << "Enter grid values:\n";
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];

    Solution sol;
    cout << "Max Product Path: " << sol.maxProductPath(grid) << endl;

    return 0;
}
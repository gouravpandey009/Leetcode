#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<long long>> prefix(m+1, vector<long long>(n+1, 0));

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                prefix[i][j] = grid[i-1][j-1]
                             + prefix[i-1][j]
                             + prefix[i][j-1]
                             - prefix[i-1][j-1];
            }
        }

        int count = 0;

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(prefix[i][j] >= 0) count++;
            }
        }

        return count;
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
    cout << "Count: " << sol.countSubmatrices(grid) << endl;

    return 0;
}
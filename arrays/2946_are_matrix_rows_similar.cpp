#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool areSimilar(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();

        k = k % n;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(i % 2 == 0) {
                    if(grid[i][j] != grid[i][(j + k) % n])
                        return false;
                } else {
                    if(grid[i][j] != grid[i][(j - k + n) % n])
                        return false;
                }
            }
        }

        return true;
    }
};

int main() {

    int m, n, k;
    cout << "Enter rows, columns and k: ";
    cin >> m >> n >> k;

    vector<vector<int>> grid(m, vector<int>(n));

    cout << "Enter grid:\n";
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];

    Solution sol;

    cout << (sol.areSimilar(grid, k) ? "True" : "False") << endl;

    return 0;
}
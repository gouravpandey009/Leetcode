#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Flips a square submatrix of size k*k starting at (x, y) vertically
    vector<vector<int>> flipSquareSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int m = grid.size();
        int n = grid[0].size();

        // Submatrix stays within grid boundaries
        if (x < 0 || y < 0 || x + k > m || y + k > n) {
            cout << "Error: Submatrix is out of bounds!" << endl;
            return grid;
        }

        int top = x;
        int bottom = x + k - 1;

        while (top < bottom) {
            for (int col = y; col < y + k; col++) {
                swap(grid[top][col], grid[bottom][col]);
            }
            top++;
            bottom--;
        }

        return grid;
    }
};

int main() {
    int m, n;
    cout << "Enter rows (m) and columns (n): ";
    if (!(cin >> m >> n)) return 0;

    vector<vector<int>> grid(m, vector<int>(n));

    cout << "Enter grid elements:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int x, y, k;
    cout << "Enter top-left coordinates (x, y) and size (k) of the square: ";
    cin >> x >> y >> k;

    Solution sol;
    vector<vector<int>> res = sol.flipSquareSubmatrix(grid, x, y, k);

    cout << "\nResulting Grid:" << endl;
    for (const auto& row : res) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
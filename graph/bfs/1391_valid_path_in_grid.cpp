#include <bits/stdc++.h>
using namespace std;

bool hasValidPath(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();

    // Added an empty first element so indices 1-6 match the street types
    vector<vector<pair<int, int>>> dirs = {
        {},
        {{0, -1}, {0, 1}},  // 1: left, right
        {{-1, 0}, {1, 0}},  // 2: up, down
        {{0, -1}, {1, 0}},  // 3: left, down
        {{0, 1}, {1, 0}},   // 4: right, down
        {{0, -1}, {-1, 0}}, // 5: left, up
        {{0, 1}, {-1, 0}}   // 6: right, up
    };

    queue<pair<int, int>> q;
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    q.push({0, 0});
    vis[0][0] = true;

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        int x = curr.first;
        int y = curr.second;
        q.pop();

        if (x == n - 1 && y == m - 1) return true;

        for (auto& d : dirs[grid[x][y]]) {
            int nx = x + d.first;
            int ny = y + d.second;

            // 1. Check grid boundaries
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || vis[nx][ny]) continue;

            // 2. Connectivity Check: The next cell must have a pipe pointing back to (x, y)
            bool canConnect = false;
            for (auto& back : dirs[grid[nx][ny]]) {
                if (nx + back.first == x && ny + back.second == y) {
                    canConnect = true;
                    break;
                }
            }

            if (canConnect) {
                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    return false;
}

int main() {
    vector<vector<int>> grid1 = {{2, 4, 3}, {6, 5, 2}};
    vector<vector<int>> grid2 = {{1, 2, 1}, {1, 2, 1}};

    cout << (hasValidPath(grid1) ? "True" : "False") << endl; 
    cout << (hasValidPath(grid2) ? "True" : "False") << endl; 

    return 0;
}

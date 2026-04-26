#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<bool>> vis;

bool dfs(int x, int y, int px, int py, vector<vector<char>>& grid) {
    vis[x][y] = true;

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    for(int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if(grid[nx][ny] != grid[x][y]) continue;

        if(!vis[nx][ny]) {
            if(dfs(nx, ny, x, y, grid)) return true;
        } 
        else if(nx != px || ny != py) {
            return true;
        }
    }

    return false;
}

bool containsCycle(vector<vector<char>>& grid) {
    n = grid.size();
    m = grid[0].size();
    vis.assign(n, vector<bool>(m, false));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!vis[i][j]) {
                if(dfs(i, j, -1, -1, grid)) return true;
            }
        }
    }

    return false;
}

int main() {
    vector<vector<char>> grid = {
        {'a','a','a','a'},
        {'a','b','b','a'},
        {'a','b','b','a'},
        {'a','a','a','a'}
    };

    cout << containsCycle(grid) << endl;
    return 0;
}

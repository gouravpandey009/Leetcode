#include <bits/stdc++.h>
using namespace std;

bool hasValidPath(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();

    vector<vector<vector<int>>> dirs = {
        {},
        {{0,-1},{0,1}},
        {{-1,0},{1,0}},
        {{0,-1},{1,0}},
        {{0,1},{1,0}},
        {{0,-1},{-1,0}},
        {{0,1},{-1,0}}
    };

    queue<pair<int,int>> q;
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    q.push({0,0});
    vis[0][0] = true;

    while(!q.empty()) {
        auto [x,y] = q.front(); q.pop();

        if(x == n-1 && y == m-1) return true;

        for(auto &d : dirs[grid[x][y]]) {
            int nx = x + d[0];
            int ny = y + d[1];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(vis[nx][ny]) continue;

            for(auto &back : dirs[grid[nx][ny]]) {
                if(nx + back[0] == x && ny + back[1] == y) {
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                    break;
                }
            }
        }
    }

    return false;
}

int main() {
    vector<vector<int>> grid = {
        {2,4,3},
        {6,5,2}
    };

    cout << hasValidPath(grid) << endl;

    return 0;
}
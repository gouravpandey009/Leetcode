#include <iostream>
#include <vector>
#include <deque>
#include <climits>

using namespace std;

class Solution {
public:

    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        int m = grid.size();
        int n = grid[0].size();

        deque<pair<int,int>> dq;

        vector<vector<int>> dist(
            m,
            vector<int>(n, INT_MAX)
        );

        dist[0][0] = grid[0][0];
        dq.push_front({0,0});

        int dr[4] = {-1,1,0,0};
        int dc[4] = {0,0,-1,1};

        while(!dq.empty()){

            auto [r,c] = dq.front();
            dq.pop_front();

            for(int k=0;k<4;k++){

                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr<0 || nr>=m || nc<0 || nc>=n)
                    continue;

                int cost = grid[nr][nc];

                if(dist[r][c] + cost < dist[nr][nc]){

                    dist[nr][nc] = dist[r][c] + cost;

                    if(cost==0)
                        dq.push_front({nr,nc});
                    else
                        dq.push_back({nr,nc});
                }
            }
        }

        return dist[m-1][n-1] < health;
    }
};

int main() {

    Solution obj;

    vector<vector<int>> grid = {
        {0,1,0,0,0},
        {0,1,0,1,0},
        {0,0,0,1,0}
    };

    int health = 1;

    cout << boolalpha
         << obj.findSafeWalk(grid, health);

    return 0;
}
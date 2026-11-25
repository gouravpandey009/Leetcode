class Solution {
private:
    using pii = pair<pair<int, int> , pair<int, int>>;
    int n , m;
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool isValid(int i , int j){
        return i >= 0 && j >= 0 && i < n && j < m;
    }


public:
    int minCost(vector<vector<int>>& grid, int k) {
        n = grid.size() , m = grid[0].size();
        if(n == 1 && m == 1) return grid[0][0];
        vector<vector<vector<vector<int>>>>dist(
            n , vector<vector<vector<int>>>(
                m , vector<vector<int>>(
                    5 , vector<int>(k + 1 , INT_MAX)
                )
            )
        );

        dist[0][0][4][0] = grid[0][0];

        priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>>>pq;

        pq.push({grid[0][0] , 0 , 0 , 4 , 0});
        
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int cost = curr[0] , i = curr[1] , j = curr[2] , prevdir = curr[3] , turn = curr[4];

            if(i == n - 1 && j == m - 1) return cost;
            if(turn > k || dist[i][j][prevdir][turn] < cost)continue;

            for(int d = 0 ; d < 4 ; d++){
                auto dir = directions[d];
                int newi = i + dir[0];
                int newj = j + dir[1];
                int newTurns = (prevdir == 4 || prevdir == d) ? turn : turn + 1;
                if(isValid(newi , newj) && newTurns <= k && dist[newi][newj][d][newTurns] > cost + grid[newi][newj]){
                    int newCost = cost + grid[newi][newj];
                    dist[newi][newj][d][newTurns] = newCost;
                    pq.push({newCost , newi , newj ,d , newTurns});
                }
            }
        }

        return -1;
    }
};
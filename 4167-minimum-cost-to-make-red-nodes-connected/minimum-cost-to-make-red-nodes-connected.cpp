using ll = long long;

class Solution {
public:

    ll minCost(int n , string C , vector<vector<int>>& E){
        vector<vector<int>> adj(n);
        for(auto& e : E){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<array<ll , 3>> dp(n);
        vector<int> sz(n , 1);

        auto dfs = [&](auto& self , int u , int p) -> void{
            ll sdp0 = 0 , sdp1 = 0;

            for(int v : adj[u]){
                if(v == p) continue;
                self(self , v , u);

                sz[u] += sz[v];
                sdp0 += dp[v][0];
                sdp1 += min(dp[v][0] , dp[v][1]);
            }

            ll cR = (C[u] == 'R') ? 0 : sz[u];
            ll cB = (C[u] == 'B') ? 0 : sz[u];

            dp[u][0] = cB + sdp0;
            dp[u][1] = cR + sdp1;
            dp[u][2] = 1e15;

            for(int v : adj[u]){
                if(v == p) continue;
                ll bi = min(dp[v][1] , dp[v][2]);
                dp[u][2] = min(dp[u][2] , cB + sdp0 + bi - dp[v][0]);
            }
        };

        dfs(dfs , 0 , -1);
        return min({dp[0][0] , dp[0][1] , dp[0][2]});
    }

};
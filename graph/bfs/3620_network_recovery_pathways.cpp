#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <utility>

using namespace std;

class Solution {
public:

    long long INF = 4e18;

    bool canAchieve(
        int node,
        int limit,
        long long budget,
        vector<vector<pair<int,int>>>& graph,
        vector<long long>& dp
    ){
        return dfs(node, limit, graph, dp) <= budget;
    }

    long long dfs(
        int node,
        int limit,
        vector<vector<pair<int,int>>>& graph,
        vector<long long>& dp
    ){
        int destination = graph.size() - 1;

        if(node == destination)
            return 0;

        if(dp[node] != -1)
            return dp[node];

        long long bestCost = INF;

        for(auto &[next, weight] : graph[node]){

            if(weight < limit)
                continue;

            long long nextCost = dfs(next, limit, graph, dp);
            if (nextCost < INF) {
                bestCost = min(bestCost, weight + nextCost);
            }
        }

        return dp[node] = bestCost;
    }

    int findMaxPathScore(
        vector<vector<int>>& edges,
        vector<bool>& online,
        long long k
    ) {
        int n = online.size();
        vector<vector<pair<int,int>>> graph(n);

        int low = INT_MAX;
        int high = 0;
        bool hasEdges = false;

        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if(!online[u] || !online[v])
                continue;

            graph[u].push_back({v,w});

            low = min(low,w);
            high = max(high,w);
            hasEdges = true;
        }

        auto possible = [&](int score){
            vector<long long> dp(n,-1);
            return dfs(0,score,graph,dp) <= k;
        };

        if(!hasEdges || !possible(low))
            return -1;

        int answer = low;

        while(low <= high){
            int mid = low + (high-low)/2;

            if(possible(mid)){
                answer = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }

        return answer;
    }
};

int main() {
    Solution solver;

    // Test Case: Simple network pathway verification
    vector<vector<int>> edges = {
        {0, 1, 10},
        {1, 3, 20},
        {0, 2, 5},
        {2, 3, 30}
    };
    vector<bool> online = {true, true, true, true};
    long long budget = 35;

    int result = solver.findMaxPathScore(edges, online, budget);
    cout << "Execution Successful! Max Path Score: " << result << " (Expected: 10)" << endl;

    return 0;
}

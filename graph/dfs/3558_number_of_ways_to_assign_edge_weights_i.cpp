#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static constexpr long long MOD = 1'000'000'007;

    long long power(long long a, long long b) {
        long long res = 1;

        while (b) {
            if (b & 1)
                res = (res * a) % MOD;

            a = (a * a) % MOD;
            b >>= 1;
        }

        return res;
    }

    int dfs(int node, int parent,
            vector<vector<int>>& graph) {

        int depth = 0;

        for (int next : graph[node]) {

            if (next == parent)
                continue;

            depth = max(
                depth,
                1 + dfs(next, node, graph)
            );
        }

        return depth;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {

        int n = edges.size() + 1;

        vector<vector<int>> graph(n + 1);

        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        int depth = dfs(1, -1, graph);

        return power(2, depth - 1);
    }
};

int main() {

    vector<vector<int>> edges = {
        {1,2},
        {1,3},
        {3,4},
        {3,5}
    };

    Solution obj;

    cout << obj.assignEdgeWeights(edges);

    return 0;
}
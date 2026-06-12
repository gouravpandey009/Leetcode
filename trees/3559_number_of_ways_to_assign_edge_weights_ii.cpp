#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    static constexpr int MOD = 1e9 + 7;
    static constexpr int LOG = 17;

    vector<vector<int>> graph;
    vector<vector<int>> up;
    vector<int> depth;
    vector<long long> pow2;

    void dfs(int node, int parent) {
        up[node][0] = parent;

        for (int j = 1; j < LOG; j++) {
            up[node][j] =
                up[node][j - 1] == -1
                    ? -1
                    : up[up[node][j - 1]][j - 1];
        }

        for (int nxt : graph[node]) {
            if (nxt == parent)
                continue;

            depth[nxt] = depth[node] + 1;
            dfs(nxt, node);
        }
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v])
            swap(u, v);

        int diff = depth[u] - depth[v];

        for (int j = LOG - 1; j >= 0; j--) {
            if (diff & (1 << j))
                u = up[u][j];
        }

        if (u == v)
            return u;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }

        return up[u][0];
    }

public:
    vector<int> assignEdgeWeights(
        vector<vector<int>>& edges,
        vector<vector<int>>& queries) {

        int n = edges.size() + 1;

        graph.assign(n + 1, {});
        depth.assign(n + 1, 0);
        up.assign(n + 1, vector<int>(LOG, -1));

        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        dfs(1, -1);

        pow2.resize(n + 1);
        pow2[0] = 1;

        for (int i = 1; i <= n; i++) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }

        vector<int> answer;

        for (auto& q : queries) {
            int u = q[0];
            int v = q[1];

            int ancestor = lca(u, v);

            int dist =
                depth[u]
                + depth[v]
                - 2 * depth[ancestor];

            if (dist == 0) {
                answer.push_back(0);
            } else {
                answer.push_back(pow2[dist - 1]);
            }
        }

        return answer;
    }
};


int main() {
   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;


    vector<vector<int>> edges = {
        {1, 2},
        {1, 3},
        {2, 4},
        {2, 5}
    };


    vector<vector<int>> queries = {
        {4, 5}, 
        {3, 4}, 
        {2, 2} 
    };

    vector<int> results = solver.assignEdgeWeights(edges, queries);

    cout << "Query Results:\n";
    for (int ans : results) {
        cout << ans << "\n";
    }

    return 0;
}

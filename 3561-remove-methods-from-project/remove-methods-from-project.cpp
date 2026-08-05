class Solution {
public:

    void dfs(int u,
             vector<vector<int>> &graph,
             vector<int> &vis) {

        vis[u] = 1;

        for (int v : graph[u]) {

            if (!vis[v])
                dfs(v, graph, vis);
        }
    }

    vector<int> remainingMethods(int n,
                                 int k,
                                 vector<vector<int>>& invocations) {

        vector<vector<int>> graph(n);

        for (auto &e : invocations)
            graph[e[0]].push_back(e[1]);

        vector<int> suspicious(n, 0);

        // Mark every suspicious method.
        dfs(k, graph, suspicious);

        // Check whether a safe method invokes
        // any suspicious method.
        for (auto &e : invocations) {

            int u = e[0];
            int v = e[1];

            if (!suspicious[u] && suspicious[v]) {

                vector<int> ans(n);

                iota(ans.begin(), ans.end(), 0);

                return ans;
            }
        }

        vector<int> ans;

        for (int i = 0; i < n; i++) {

            if (!suspicious[i])
                ans.push_back(i);
        }

        return ans;
    }
};
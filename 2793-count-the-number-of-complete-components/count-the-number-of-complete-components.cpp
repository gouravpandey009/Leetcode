class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> g(n);

        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        vector<int> vis(n);
        int ans = 0;

        for (int i = 0; i < n; i++) {

            if (vis[i]) continue;

            queue<int> q;
            q.push(i);
            vis[i] = 1;

            int nodes = 0;
            int degreeSum = 0;

            while (!q.empty()) {

                int u = q.front();
                q.pop();

                nodes++;
                degreeSum += g[u].size();

                for (int v : g[u]) {
                    if (!vis[v]) {
                        vis[v] = 1;
                        q.push(v);
                    }
                }
            }

            if (degreeSum == nodes * (nodes - 1))
                ans++;
        }

        return ans;
    }
};
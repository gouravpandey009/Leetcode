class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> graph(n);

        // Build the graph.
        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<int> vis(n, 0);
        int complete = 0;

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

                // Every adjacent node contributes one degree.
                degreeSum += graph[u].size();

                for (int v : graph[u]) {
                    if (!vis[v]) {
                        vis[v] = 1;
                        q.push(v);
                    }
                }
            }

            // Complete graph with k nodes has:
            // k * (k - 1) / 2 edges.
            // Degree sum counts every edge twice.
            if (degreeSum == nodes * (nodes - 1))
                complete++;
        }

        return complete;
    }
};
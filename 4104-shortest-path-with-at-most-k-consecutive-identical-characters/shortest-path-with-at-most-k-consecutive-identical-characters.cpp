class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto& e : edges) adj[e[0]].push_back({e[1] , e[2]});
        vector<long long> dist((size_t)n * k , LLONG_MAX);
        priority_queue<pair<long long , int>, vector<pair<long long , int>>  , greater<pair<long long , int>>> pq;
        dist[0] = 0;
        pq.push({0 , 0});
        while(!pq.empty()){
            auto [d , state] = pq.top();
            pq.pop();
            if(d > dist[state]) continue;
            int u = state / k;
            int run = state % k + 1;
            if(u == n - 1) return(int)d;
            for(auto& [v , w] : adj[u]){
                int nr = (labels[v] == labels[u]) ? run + 1 : 1;
                if(nr > k) continue;
                int ns = v * k + nr - 1;
                long long nd = d + w;
                if(nd < dist[ns]){
                    dist[ns] = nd;
                    pq.push({nd , ns});
                }
            }
        }

        return -1;
    }
};
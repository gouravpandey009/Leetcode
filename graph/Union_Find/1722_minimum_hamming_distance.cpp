#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if(parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if(px == py) return;

        if(rank[px] < rank[py]) parent[px] = py;
        else if(rank[px] > rank[py]) parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }
    }
};

int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
    int n = source.size();
    DSU dsu(n);

    for(auto &e : allowedSwaps) {
        dsu.unite(e[0], e[1]);
    }

    unordered_map<int, unordered_map<int, int>> comp;

    for(int i = 0; i < n; i++) {
        int p = dsu.find(i);
        comp[p][source[i]]++;
    }

    int ans = 0;

    for(int i = 0; i < n; i++) {
        int p = dsu.find(i);

        if(comp[p][target[i]] > 0) {
            comp[p][target[i]]--;
        } else {
            ans++;
        }
    }

    return ans;
}

int main() {
    vector<int> source = {1,2,3,4};
    vector<int> target = {2,1,4,5};
    vector<vector<int>> allowedSwaps = {{0,1},{2,3}};

    cout << minimumHammingDistance(source, target, allowedSwaps) << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    struct DSU {
        vector<int> parent, rank;

        DSU(int n){
            parent.resize(n);
            rank.resize(n,0);
            for(int i=0;i<n;i++)
                parent[i]=i;
        }

        int find(int x){
            if(parent[x]==x)
                return x;
            return parent[x]=find(parent[x]);
        }

        bool unite(int a,int b){

            a=find(a);
            b=find(b);

            if(a==b)
                return false;

            if(rank[a]<rank[b])
                swap(a,b);

            parent[b]=a;

            if(rank[a]==rank[b])
                rank[a]++;

            return true;
        }
    };

    long long maximumStability(int n, vector<vector<int>>& edges){

        sort(edges.begin(), edges.end(),
             [](auto &a, auto &b){
                 return a[2] > b[2];
             });

        DSU dsu(n);

        long long ans = 0;
        int used = 0;

        for(auto &e:edges){

            int u=e[0];
            int v=e[1];
            int w=e[2];

            if(dsu.unite(u,v)){
                ans += w;
                used++;

                if(used==n-1)
                    break;
            }
        }

        if(used != n-1)
            return -1;

        return ans;
    }
};

int main(){

    int n,m;
    cin>>n>>m;

    vector<vector<int>> edges(m, vector<int>(3));

    for(int i=0;i<m;i++){
        cin>>edges[i][0]>>edges[i][1]>>edges[i][2];
    }

    Solution sol;

    cout<<sol.maximumStability(n,edges)<<endl;

    return 0;
}
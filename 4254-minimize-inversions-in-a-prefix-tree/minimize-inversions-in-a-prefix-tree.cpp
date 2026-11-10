class Solution {
public:
    int minInversions(vector<string>& words, vector<int>& target) {
        vector<array<int , 10>> children(1, array<int, 10>{});
        vector<int>slot(1 , 0);
        vector<int>degree(1 , 0);
        for(const string &word :words){
            int u = 0;
            for(char ch : word){
                int c = ch - 'a';
                if(children[u][c] == 0){
                    int v = static_cast<int>(children.size());
                    children[u][c] = v;
                    slot.push_back(degree[u]++);
                    degree.push_back(0);
                    children.push_back(array<int , 10>{});
                }
                u = children[u][c];
            }
        }

        int nodes = static_cast<int>(children.size());
        vector<vector<long long>>cost(nodes);
        for(int u = 0 ;u < nodes; ++u){
            if(degree[u] > 1){
                cost[u].assign(degree[u] * degree[u] , 0);
            }
        }

        vector<int>seen(nodes ,0);
        long long answer = 0;
        for(int idx : target){
            int u = 0;
            for(char ch : words[idx]){
                int v = children[u][ch - 'a'];
                if(degree[u] > 1){
                    int k = degree[u];
                    int base = slot[v] * k;
                    for(int sibling : children[u]){
                        if(sibling != 0 && sibling != v){
                            cost[u][base + slot[sibling]] += seen[sibling]; 
                        }
                    }
                }

                ++seen[v];
                u = v;
            }

            answer += seen[u] - 1;
        }

        for(int u = 0 ; u < nodes ; ++u){
            int k = degree[u];
            if(k <= 1){
                continue;
            }

            int size = 1 << k;
            vector<vector<long long>> sums(k , vector<long long>(size , 0));
            for(int i = 0 ; i < k ; i++){
                for(int mask = 1 ; mask < size ; ++mask){
                    int bit = mask & -mask;
                    int j = __builtin_ctz(static_cast<unsigned>(bit));
                    sums[i][mask] = sums[i][mask ^ bit] + cost[u][i * k + j];
                }
            }

            const long long INF = 1ll << 60;
            vector<long long> dp(size , INF);
            dp[0] = 0;

            for(int mask = 1 ; mask < size ; mask++){
                for(int bits = mask ; bits != 0 ; bits &= bits - 1){
                    int bit = bits & - bits;
                    int i = __builtin_ctz(static_cast<unsigned>(bit));
                    int rest = mask ^ bit;
                    dp[mask] = min(dp[mask] , dp[rest] + sums[i][rest]);
                }
            }

            answer += dp[size - 1];
        }

        return static_cast<int>(answer);
    }
};
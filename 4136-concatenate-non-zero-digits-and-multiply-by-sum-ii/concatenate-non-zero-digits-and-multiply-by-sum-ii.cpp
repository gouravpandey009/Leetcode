#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    struct Node {
        int v, c;
    };

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<int> p(n + 1, 1), pre(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            p[i] = 1LL * p[i - 1] * 10 % MOD;
        }
        for(int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + (s[i] - '0');
        }

        vector<Node> st(2 * n);
        for(int i = 0; i < n; i++){
            st[n + i] = (s[i] == '0') ? Node{0, 0} : Node{s[i] - '0', 1};
        }

        
        auto merge = [&](const Node& a, const Node& b) {
            return Node{
                (int)((1LL * a.v * p[b.c] + b.v) % MOD),
                a.c + b.c
            }; 
        };

        for(int i = n - 1; i > 0; --i){
            st[i] = merge(st[i << 1], st[i << 1 | 1]);
        } 

        vector<int> ans;
        ans.reserve(queries.size());

        for(auto& q : queries){
           
            int l = q[0] + n, r = q[1] + n; 

            Node L {0, 0}, R {0, 0};

            while(l <= r){ 
                if(l & 1) L = merge(L, st[l++]);
                if(!(r & 1)) R = merge(st[r--], R);
                l >>= 1;
                r >>= 1;
            }

            Node x = merge(L, R);

            
            long long range_sum = pre[q[1] + 1] - pre[q[0]];

            ans.push_back(1LL * x.v * range_sum % MOD); 
        }
        
        return ans;
    }
};

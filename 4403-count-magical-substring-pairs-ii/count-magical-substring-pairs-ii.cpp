class Solution {
public:
    #define ll long long

    ll countMagicalPairs(string s) {
        int n = s.size();
        vector<array<int , 26>> nxt(n + 1) , prv(n);

        for(int c = 0 ; c < 26 ; ++c){
            nxt[n][c] = n;
            prv[0][c] = -1;
        }

        for(int i = n - 1 ; i >= 0 ; --i){
            nxt[i] = nxt[i + 1];
            nxt[i][s[i] - 'a'] = i;
        }

        array<int , 26> cur;
        cur.fill(-1);

        for(int i = 0 ; i < n ; ++i){
            cur[s[i] - 'a'] = i;
            prv[i] = cur;
        }

        ll res = 0;

        for(int j = 0 ; j + 1 < n; ++j){
            vector<int>lp , rp;

            for(int c = 0 ; c < 26 ; ++c){
                if(prv[j][c] != -1)
                lp.push_back(prv[j][c]);

                if(nxt[j + 1][c] != n)
                rp.push_back(nxt[j + 1][c]);
            }

            sort(lp.rbegin() , lp.rend());
            sort(rp.begin() , rp.end());

            ll cntL[27] = {} , cntR[27] = {};
            int szL = lp.size() , szR = rp.size();

            for(int t = 0 ; t < szL ; t++){
                int hi = lp[t];
                int lo = (t + 1 < szL) ? lp[t + 1] + 1 : 0;
                if(lo <= hi)
                cntL[t + 1] += hi - lo + 1;
            }

            for(int t = 0 ; t < szR ; ++t){
                int lo = rp[t];
                int hi = (t + 1 < szR) ?  rp[t + 1] - 1 : n - 1;

                if(lo <= hi)
                cntR[t + 1] += hi - lo + 1;
            }

            for(int k = 1 ; k <= 26 ; ++k)
            res += cntL[k] * cntR[k];
        }
        return res;
    }
};
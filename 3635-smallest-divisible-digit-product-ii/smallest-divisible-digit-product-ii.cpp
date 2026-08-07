class Solution {
public:

    // Prime factors contributed by each digit.
    const int contrib[10][4] = {
        {0,0,0,0},
        {0,0,0,0},
        {1,0,0,0},
        {0,1,0,0},
        {2,0,0,0},
        {0,0,1,0},
        {1,1,0,0},
        {0,0,0,1},
        {3,0,0,0},
        {0,2,0,0}
    };

    vector<int> primes = {2,3,5,7};

    int E2, E3, E5, E7;

    // dp[e2][e3][e5][e7]
    // Minimum digits required to satisfy the remaining exponents.
    vector<vector<vector<vector<int>>>> dp;

    //---------------------------------------------------------------

    long long nCr(long long n,long long r,long long limit){

        r=min(r,n-r);

        long long ans=1;

        for(long long i=1;i<=r;i++){

            ans=ans*(n-i+1)/i;

            if(ans>limit)
                return limit+1;
        }

        return ans;
    }

    //---------------------------------------------------------------

    void buildDP(int a,int b,int c,int d){

        E2=a;
        E3=b;
        E5=c;
        E7=d;

        dp.assign(
            E2+1,
            vector<vector<vector<int>>>(
                E3+1,
                vector<vector<int>>(
                    E5+1,
                    vector<int>(E7+1,INT_MAX)
                )
            )
        );

        dp[0][0][0][0]=0;

        int total=E2+E3+E5+E7;

        for(int sum=1;sum<=total;sum++){

            for(int e2=0;e2<=E2;e2++)
            for(int e3=0;e3<=E3;e3++)
            for(int e5=0;e5<=E5;e5++)
            for(int e7=0;e7<=E7;e7++){

                if(e2+e3+e5+e7!=sum)
                    continue;

                int best=INT_MAX;

                for(int digit=2;digit<=9;digit++){

                    int p2=max(0,e2-contrib[digit][0]);
                    int p3=max(0,e3-contrib[digit][1]);
                    int p5=max(0,e5-contrib[digit][2]);
                    int p7=max(0,e7-contrib[digit][3]);

                    if(dp[p2][p3][p5][p7]!=INT_MAX){

                        best=min(
                            best,
                            dp[p2][p3][p5][p7]+1
                        );
                    }
                }

                dp[e2][e3][e5][e7]=best;
            }
        }
    }

    //---------------------------------------------------------------

    int need(int e2,int e3,int e5,int e7){

        return dp[
            min(e2,E2)
        ][
            min(e3,E3)
        ][
            min(e5,E5)
        ][
            min(e7,E7)
        ];
    }

    //---------------------------------------------------------------

    void useDigit(vector<int>& req,int digit){

        req[2]=max(0,req[2]-contrib[digit][0]);
        req[3]=max(0,req[3]-contrib[digit][1]);
        req[5]=max(0,req[5]-contrib[digit][2]);
        req[7]=max(0,req[7]-contrib[digit][3]);
    }

    //---------------------------------------------------------------

    bool finished(vector<int>& req){

        return req[2]==0 &&
               req[3]==0 &&
               req[5]==0 &&
               req[7]==0;
    }

    //---------------------------------------------------------------

    string buildSmallest(vector<int> req,int len){

        string ans;

        for(int pos=0;pos<len;pos++){

            int remain=len-pos-1;

            for(int digit=1;digit<=9;digit++){

                auto nxt=req;

                useDigit(nxt,digit);

                if(
                    need(
                        nxt[2],
                        nxt[3],
                        nxt[5],
                        nxt[7]
                    )<=remain
                ){

                    ans.push_back('0'+digit);

                    req=nxt;

                    break;
                }
            }
        }

        return ans;
    }

    //---------------------------------------------------------------

    string smallestNumber(string num,long long t) {

        vector<int> req(10);

        for(int p:primes){

            while(t%p==0){

                req[p]++;

                t/=p;
            }
        }

        // Contains some other prime factor.
        if(t>1)
            return "-1";

        buildDP(
            req[2],
            req[3],
            req[5],
            req[7]
        );

        int n=num.size();

        bool hasZero=false;

        for(char c:num){

            if(c=='0'){

                hasZero=true;
                break;
            }
        }

        //-----------------------------------------------------------
        // Already valid.
        //-----------------------------------------------------------

        if(!hasZero){

            auto cur=req;

            for(char c:num)
                useDigit(cur,c-'0');

            if(finished(cur))
                return num;
        }

        //-----------------------------------------------------------
        // Prefix requirements.
        //-----------------------------------------------------------

        vector<vector<int>> pref(n+1);

        pref[0]=req;

        for(int i=0;i<n;i++){

            pref[i+1]=pref[i];

            if(num[i]!='0')
                useDigit(pref[i+1],num[i]-'0');
        }

        int last=hasZero ?
                 num.find('0')
                 :
                 n-1;

        string ans;

        //-----------------------------------------------------------
        // Same length.
        //-----------------------------------------------------------

        for(int pos=last;pos>=0 && ans.empty();pos--){

            auto before=pref[pos];

            for(int digit=num[pos]-'0'+1;
                digit<=9;
                digit++){

                auto nxt=before;

                useDigit(nxt,digit);

                int remain=n-pos-1;

                if(
                    need(
                        nxt[2],
                        nxt[3],
                        nxt[5],
                        nxt[7]
                    )<=remain
                ){

                    ans=
                        num.substr(0,pos)
                        +
                        char('0'+digit)
                        +
                        buildSmallest(
                            nxt,
                            remain
                        );

                    break;
                }
            }
        }

        if(!ans.empty())
            return ans;

        //-----------------------------------------------------------
        // Increase length.
        //-----------------------------------------------------------

        int len=max(
            n+1,
            need(
                req[2],
                req[3],
                req[5],
                req[7]
            )
        );

        return buildSmallest(req,len);
    }
};
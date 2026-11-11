class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if(need1 == 0 && need2 == 0){
            return 0;
        }

        long long ans = LLONG_MAX;
        long long x;

        x = 0;
        ans = min(
            ans , 
            x * (long long) costBoth + need1 * (long long)cost1 + need2 * (long long ) cost2);

            x = min(need1 , need2);
            ans = min(ans ,
            x * (long long)costBoth + (need1 - x) * (long long) cost1 + (need2 - x) * (long long)cost2);

            x = max(need1 , need2);
            ans = min(ans ,
            x * (long long) costBoth + max(0LL , need1 - x) * (long long)cost1 + max(0LL , need2 - x) * (long long)cost2);

            return ans;
    }
};
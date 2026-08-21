class Solution {
public:
    long long gcd(long long a  , long long b){
        while(b != 0){
            long long temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }
    
    long long lcm(long long a , long long b){
        return a  / gcd(a , b) * b;
    }

    long long solve(long long mid , vector<int>& coins)
    {
        sort(coins.begin() , coins.end());

        vector<int>f;
        
        for(int i = 0 ; i < coins.size() ; i++){
            bool red = false;

            for(int z : f){
                if(coins[i] % z == 0){
                    red = true;
                    break;
                }
            }

            if(!red)
            f.push_back(coins[i]);
        }

        coins = f;

        int n = coins.size();
        long long ans = 0;
        

        for(int mask = 1; mask <(1 << n) ; mask++){
            int bits = 0;
            long long x = 1;
            bool check = false;


            for(int j = 0 ; j < n ; j++){
                if(mask & (1 << j)){
                    x = lcm(x , coins[j]);
                    bits++;

                    if(x > mid){
                        check = true;
                        break;
                    }
                }
            }

            if(check)
                continue;

                long long curr = mid / x;

                if(bits % 2 )
                ans += curr;

                else 
                ans -= curr;
        }

        return ans;
    }




    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        int mini = *min_element(coins.begin() , coins.end());

        long long low = 1;
        long long high = 1LL * mini * k;

        while(low <= high){
            long long mid = low + (high - low) / 2;

            if(solve(mid , coins) >= k)
            high = mid - 1;
            else
                low = mid + 1;
        }

        return low;
    }
};
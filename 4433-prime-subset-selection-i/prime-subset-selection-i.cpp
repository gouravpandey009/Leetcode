class Solution {
public:
    vector<int> maxPrimes(int n, int s) {
        vector<bool> sieve(n + 1, true);
        sieve[0] = false;
        if(n >= 1){
            sieve[1] = false;
        }

        for(int i = 2 ; i * i <= n + 1; i++){
            if(sieve[i]){
                for(int j = i * i ; j < n + 1 ; j += i){
                    sieve[j] = false;
                }
            }
        }

        vector<int> sol;
        int sum = 0;
        for(int i = 2 ; i <= n; i++){
            if(!sieve[i]){
                continue;
            }

            if(sum + i > s){
                break;
            }

            sum += i;
            sol.push_back(i);
        }

        return sol;
    }
};
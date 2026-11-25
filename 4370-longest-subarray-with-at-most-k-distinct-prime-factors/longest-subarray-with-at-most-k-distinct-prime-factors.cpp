class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int maxi = *max_element(nums.begin() , nums.end());
        vector<int> spf(maxi + 1);
        for(int i = 2 ; i <= maxi ; i++){
            if(spf[i] == 0){
                for(int j = i ; j <= maxi ; j += i){
                    if(spf[j] == 0) spf[j] = i;
                }
            }
        }

        int n = nums.size();
        vector<vector<int>> primeFactors(n);
        for(int i = 0 ; i < n ; i++){
            int num= nums[i];
            vector<int> primes;
            while(num > 1){
                int p = spf[num];
                primes.push_back(p);
                while(num % p == 0) num /= p;
            }

            primeFactors[i] = primes;
        }

        unordered_map<int , int> freq;
        int l = 0 ,distinct = 0 , maxLen = 0;

        for(int r = 0 ; r < n ; r++){
            for(int p : primeFactors[r]){
                if(freq[p] == 0) distinct++;
                freq[p]++;
            }

            while(distinct > k){
                for(int p : primeFactors[l]){
                    freq[p]--;
                    if(freq[p] == 0) distinct--;
                }

                l++;
            }

            maxLen = max(maxLen , r - l + 1);
        }

        return maxLen;
    }
};
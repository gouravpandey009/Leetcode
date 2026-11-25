class Solution {
public:
    int helper(vector<int> &arr){
        int n = arr.size();
        if(n < 2) return 0;

        vector<int> prefix(n , 0);
        vector<int> suffix(n  , 0);
        prefix[0] = arr[0];
        suffix[n - 1] = arr[n - 1];

        for(int i = 1 ; i <= n - 1 ; i++){
            prefix[i] = gcd(prefix[i - 1] , arr[i]);
        }

        for(int i = n - 2 ; i >= 0 ; i--){
            suffix[i] = gcd(suffix[i + 1] , arr[i]);

        }

        for(int i = n - 2 ; i >= 0 ; i--){
            suffix[i] = gcd(suffix[i + 1] , arr[i]);
        }

        int c = 0;
        for(int i = 0 ; i <= n - 2; i++){
            if(prefix[i] == suffix[i + 1]){
                c++;
            }
        }

        return c;
    }


    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n ,0);
        vector<int> suffix(n , 0);
        prefix[0] = nums[0];
        suffix[n - 1] = nums[n - 1];

        for(int i = 1 ; i <= n - 1; i++){
            prefix[i] = gcd(prefix[i - 1] , nums[i]);
        }

        for(int i = n - 2; i >= 0 ; i--){
            suffix[i] = gcd(suffix[i + 1] , nums[i]);
        }

        vector<int>trouble;
        for(int i = 1 ; i <= n - 1; i++){
            if(prefix[i] != prefix[i - 1]){
                trouble.push_back(i);
            }

            if(suffix[i] != suffix[i - 1]){
                trouble.push_back(i - 1);
            }
        }

        int maxi = 0;
        trouble.push_back(-1);
        trouble.push_back(0);
        trouble.push_back(n - 1);
        for(int i : trouble){
            if(i == -1){
                maxi = max(maxi , helper(nums));
            }
            else {
                vector<int> arr;
                for(int j = 0 ; j <= n - 1; j++){
                    if(j != i){
                        arr.push_back(nums[j]);
                    }
                }

                maxi = max(maxi , helper(arr));
            }
        }

        return maxi;

        
    }
};
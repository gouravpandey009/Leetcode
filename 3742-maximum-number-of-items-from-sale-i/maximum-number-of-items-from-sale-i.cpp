class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> facs(n, 0);

        for(int i = 0; i < items.size(); i++){
            for(int j = 0; j < items.size(); j++){
                if(i != j && items[j][0] % items[i][0] == 0) facs[i]++;
            }
        }

        vector<int> dp(budget + 1, INT_MIN); 
        dp[0] = 0;
        
        for(int i = 0; i < n; i++){
            int p = items[i][1];
            int bonus = facs[i];
            

            vector<int> next_dp = dp;
            

            for(int c = 0; c <= budget; c++){
                if(dp[c] != INT_MIN && c + p <= budget) {
                    next_dp[c + p] = max(next_dp[c + p], dp[c] + 1 + bonus);
                }
            }
            
            for(int c = p; c <= budget; c++){
                if(next_dp[c - p] != INT_MIN) {
                    next_dp[c] = max(next_dp[c], next_dp[c - p] + 1);
                }
            }
            
    
            for(int c = 0; c <= budget; c++){
                next_dp[c] = max(next_dp[c], dp[c]);
            }
            
            dp = next_dp;
        }

        return *max_element(dp.begin(), dp.end());
    }
};
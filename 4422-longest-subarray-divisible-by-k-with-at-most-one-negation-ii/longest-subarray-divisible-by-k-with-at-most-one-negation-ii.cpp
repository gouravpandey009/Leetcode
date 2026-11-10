class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> first(k, n + 1), last(k, -1);
        first[0] = 0;
        last[0] = 0; 
        
        vector<vector<int>> pos(k);
        long long pref = 0;
        
        for (int i = 0; i < n; i++) {
   
            int val = ((nums[i] % k) + k) % k; 
            pos[val].push_back(i);
        
            pref = (pref + val) % k;
            
            if (first[pref] == n + 1) first[pref] = i + 1;
            last[pref] = i + 1;
        }

        int ans = 0;
        for (int j = 0; j < k; j++) {
            if (first[j] != n + 1) {
                ans = max(ans, last[j] - first[j]);
            }
        }

        for (int i = 0; i < k; ++i) {
            if (pos[i].empty()) continue;
            
            int target = (2 * i) % k;
            
            for (int j = 0; j < k; ++j) {
                if (first[j] == n + 1) continue;
                
                int r = (j + target) % k;
                if (last[r] == -1) continue;
                
                if (last[r] - first[j] <= ans) continue;
                
                auto it = lower_bound(pos[i].begin(), pos[i].end(), first[j]);
                if (it != pos[i].end() && *it < last[r]) {
                    ans = last[r] - first[j];
                }
            }
        }
        
        return ans;
    }
};
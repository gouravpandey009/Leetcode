class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        
        // max d such that d*(d+1)/2 <= n
        int max_d = 0;
        while ((max_d + 1) * (max_d + 2) / 2 <= n) {
            max_d++;
        }

        vector<int> freq(100001, 0);
        vector<int> target(100001, 0);
        vector<int> distinct;
        distinct.reserve(max_d + 5);

        for (int i = 0; i < n; i++) {
            distinct.clear();
            int matched = 0;

            for (int j = i; j < n; j++) {
                int x = nums[j];

                if (freq[x] == 0) {
                    distinct.push_back(x);
                    int d = distinct.size();
                    
                    // array remaining isn't long enough for 'd' distinct elements
                    if (i + d * (d + 1) / 2 > n) break;
                    
                    target[x] = d;
                }

                freq[x]++;

                if (freq[x] == target[x]) {
                    matched++;
                } else if (freq[x] > target[x]) {
                    // Over-frequency invalidates this and any further extension
                    break;
                }

                int d = distinct.size();
                int len = j - i + 1;
                
                if (len == d * (d + 1) / 2 && matched == d) {
                    ans++;
                }
            }
            for (int x : distinct) {
                freq[x] = 0;
                target[x] = 0;
            }
        }

        return ans;
    }
};
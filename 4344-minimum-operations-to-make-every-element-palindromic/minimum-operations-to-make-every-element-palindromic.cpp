class Solution {
public:
    long long minOperations(vector<int>& nums) {
        static vector<long long> a , b;
        if(a.empty()){
            for(int i = 1 ; i <= 10 ; i++){
                int h = (i + 1) / 2;
                long long l = 1;
                for(int j = 1 ; j < h ; j++) 
                l *=10;
                for(long long j = l ; j < l * 10 ; j++){
                    string x = to_string(j) , y = x;
                    int m = x.size();
                    for(int k = (i % 2 ? m - 2 : m - 1) ; k >= 0 ; k--) 
                    y += x[k];
                    long long v = stoll(y);
                    if(v % 2 == 0) a.push_back(v);
                    else b.push_back(v);
                }
            }

            sort(a.begin() , a.end());
            sort(b.begin() , b.end());
        }


        long long ans = 0;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            vector<long long>& c = (nums[i]% 2 == 0) ? a : b;
            int j = lower_bound(c.begin() , c.end() , (long long)nums[i]) - c.begin();
            long long mn = -1;
            if(j <(int)c.size()) mn = c[j] - nums[i];
            if(j > 0 && (mn < 0 || (nums[i] - c[j - 1]) < mn)) mn = nums[i] - c[j - 1];
            ans += mn / 2;

        }

        return ans;
    }


};
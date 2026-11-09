class Solution {
public:
    vector<int> countSuffix(vector<int>& nums, vector<int>& target) {
        int n = nums.size() , 
        m = target.size(), 
        T = n + m;

        int a[n + 10];
        memset(a , 0 , sizeof(a));
        int b[m + 10];
        memset(b , 0 , sizeof(b));

        for(int i = 1 ; i <= n ; i++) a[i] = nums[i - 1];
        for(int i = 1; i <= m; i++) b[i] = target[i - 1];

        int s[T + 10];
        memset(s , 0 , sizeof(s));
        for(int i = 1 ; i <= n ; i++)
        s[i] = a[i];
        for(int i = 1 ; i <= m; i++)
        s[n + i] = b[i];

        int z[T + 10];
        memset(z , 0 , sizeof(z));
        for(int i = 2 ,  l = 0 , r = 0 ;  i <= T ; i++){
            z[i] = i <= r ? min(z[i - l + 1] , r - i + 1) : 0;
            while(i + z[i] <= T && s[1 + z[i]] == s[i + z[i]]) z[i]++;
            if(i + z[i] - 1 > r)
            l = i , r = i + z[i] - 1;
        }

        int f[m + 10];
        memset(f , 0 , sizeof(f));
        for(int i = 1 ; i <= m ; i++)
        f[i] = (b[i - 1] >= b[i] ? f[i - 1] : 0) + 1;

        vector<int>ans;
        unordered_map<int,int>cnt;
        int dif = 0;

        for(int i = 1 ;  i <= n ; i++) 
        dif += ++cnt[a[i]] == 1;
        for(int i = 1 ; i <= m ; i++){
            dif += --cnt[b[i]] == 0 ? -1 : (cnt[b[i]] == -1 ? 1 : 0);
            if(i - n >= 1) dif += ++cnt[b[i - n]] == 0 ? -1 : (cnt[b[i - n]] == 1 ? 1 : 0);

            if(i < n) continue;
            else if(dif != 0) ans.push_back(0);
            else {
                int l = z[n + (i - n + 1)];
                int r = n - min(f[i] , n) + 1;
                ans.push_back(max(min(l + 1, n) - r + 1 , 0));
            }
        }

        return ans;
    }
};
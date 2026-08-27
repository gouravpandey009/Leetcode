class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26 , 0);

        for(char c  : s){
            cnt[c - 'a']++;
        }

        string prefix;

        for(int i = 0 ; i < n ; i++){
            int x = target[i] - 'a';

            if(cnt[x] == 0){
                break;
            }

            cnt[x]--;
            prefix += target[i];
        }

        if((int)prefix.size() < n){
            int i = prefix.size();
            int x = target[i] - 'a';

            for(int c = x + 1 ; c < 26 ; c++){
                if(cnt[c] == 0)
                continue;

                string ans = prefix;
                ans += char('a' + c);

                cnt[c]--;

                for(int ch = 0 ; ch < 26 ; ch++){
                    ans.append(cnt[ch] , char('a' + ch));
                }

                return ans;
            }
        }

        for(int i = prefix.size() - 1 ;  i >= 0 ; i--){
            cnt[prefix[i] - 'a']++;
            prefix.pop_back();

            int x = target[i] - 'a';

            for(int c = x + 1 ; c < 26 ; c++){
                if(cnt[c] == 0)
                continue;

                string ans = prefix;

                ans += char('a' + c);
                cnt[c]--;

                for(int ch = 0 ; ch < 26 ; ch++){
                    ans.append(cnt[ch] , char('a' + ch));
                }

                return ans;
            }
        }

        return "";
    }
};
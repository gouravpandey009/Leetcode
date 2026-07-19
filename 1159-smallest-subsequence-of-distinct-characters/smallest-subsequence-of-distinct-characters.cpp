class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last(26);
        vector<bool> visited(26 , false);

        for(int i = 0 ; i < s.size() ; i++){
            last[s[i] - 'a'] = i;
        }

        string ans;

        for(int i = 0 ; i < s.size() ; i++){
            char ch = s[i];

            if(visited[ch - 'a']) continue;

            while(!ans.empty() && ans.back() > ch && last[ans.back() - 'a'] > i){
                visited[ans.back() - 'a'] = false;
                ans.pop_back();
            }

            ans.push_back(ch);
            visited[ch - 'a'] = true;
        }

        return ans;


    }
};
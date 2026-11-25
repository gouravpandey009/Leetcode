class Solution {
public:
    int countRotations(string s, int k) {
        string s1 = s;
        int ans = 0;
        for(int j = 0 ; j <= s.size() - 1 ; j++){
            int score = 0;
            string temp = s.substr(0 , j);
            string t = s.substr(j);
            s = t + temp;
            for(int i = 0 ; i < s.size(); i++){
                if(0 <= i && s.size() - 1 && s[i] == s[i  + 1])
                score += 1;
            }

            if(score == k)
            ++ans;
            s = s1;
        }

        return ans;
    }
};
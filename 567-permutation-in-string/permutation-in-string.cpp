class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int f1[26] = {};
        int f2[26] = {};

        for(char c : s1){
            f1[c - 'a']++;
        }

        int k = s1.size();

        //window size for s2

        for(int i = 0 ; i < s2.size() ; i++){
            f2[s2[i] - 'a']++;

        if(i >= k){
            f2[s2[i - k ] - 'a']--;
        }

        if(i >= k - 1) {
            bool same = true;

            for(int j = 0 ; j < 26 ; j++){
                if(f1[j] != f2[j]){
                    same = false;
                    break;
                }
            }

            if(same) 
            return true;
        }  

        }

        return false;

        }
};
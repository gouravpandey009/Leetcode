class Solution {
public:
    bool palin(string& s){
        int i = 0;
        int j = s.size() - 1;
        while(i < j){
            if(s[i] != s[j]){
                return false;
            }

            i++;
            j--;
        }

        return true;
    }
    bool isPalindromic(string s) {
        string binary;
        for(int i = 0 ; i < s.size() ; i++){
            char ch = s[i];
            int ascii = (int)ch;
            string hold = bitset<8>(ascii).to_string();
            binary += hold;
        }

        return palin(binary);
    }
};
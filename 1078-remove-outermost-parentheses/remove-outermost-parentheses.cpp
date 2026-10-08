class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int level = 0;
        for(auto& c : s)
        if(c & 1 ? --level : level++)
        res  += c;

        return res;
    }
};
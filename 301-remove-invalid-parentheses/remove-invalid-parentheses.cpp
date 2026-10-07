class Solution {
public:
    int n;
    unordered_set<string> st;

    void solve(string& s, int i, string& cur, int count, int remL, int remR) {
        if (count < 0 || remL < 0 || remR < 0) return;
        
        if (i == n) {
            if (count == 0 && remL == 0 && remR == 0) {
                st.insert(cur);
            }
            return;
        }
        if (s[i] != ')' && s[i] != '(') {
            cur.push_back(s[i]);
            solve(s, i + 1, cur, count, remL, remR);
            cur.pop_back();
            return;
        }

        //  Keep current character
        cur.push_back(s[i]);
        solve(s, i + 1, cur, count + (s[i] == '(' ? 1 : -1), remL, remR);
        cur.pop_back();

        //  Remove current character
        if (s[i] == '(' && remL > 0) {
            solve(s, i + 1, cur, count, remL - 1, remR);
        } else if (s[i] == ')' && remR > 0) {
            solve(s, i + 1, cur, count, remL, remR - 1);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        n = s.length();
        st.clear();

        int remL = 0, remR = 0;
        for (char c : s) {
            if (c == '(') {
                remL++;
            } else if (c == ')') {
                if (remL > 0) remL--;
                else remR++;
            }
        }

        string curr = "";

        solve(s, 0, curr, 0, remL, remR);

        return vector<string>(begin(st), end(st));
    }
};
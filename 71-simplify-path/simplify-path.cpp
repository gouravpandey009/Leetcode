class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string part = "";

        for (int i = 0; i <= path.size(); i++) {

            if (i == path.size() || path[i] == '/') {

                if (part == "" || part == ".") {
                }
                else if (part == "..") {
                    if (!st.empty()) {
                        st.pop();
                    }
                }
                else {
                    st.push(part);
                }
                part = "";
            }
            else {
                part += path[i];
            }
        }
        string ans = "";

        while (!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }
        if (ans == "") {
            return "/";
        }

        return ans;
    }
};
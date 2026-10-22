class Solution {
public:
    bool isValid(string s) {

        stack<char>st;

        for(char ch : s){
            //if opening bracket we have to push into the stack

            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }

            //closing bracket

            else{
                if(st.empty()){
                    return false;
                }

                if(ch == ')' && st.top() != '('){
                    return false;
                }

                if(ch == '}' && st.top()!= '{'){
                    return false;
                }

                if(ch == ']' && st.top()!= '['){
                    return false;

                }

                st.pop();
            }

            
        }
        return st.empty();
    }
};
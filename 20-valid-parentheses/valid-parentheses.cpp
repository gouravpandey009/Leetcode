#include <stack>
#include <unordered_map>

class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack;
        std::unordered_map<char, char> brackets = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        
        for (char ch : s) {
            if (brackets.count(ch)) {
                if (stack.empty() || stack.top() != brackets[ch]) {
                    return false;
                }
                stack.pop();
            } else {
                stack.push(ch);
            }
        }
        
        return stack.empty();
    }
};
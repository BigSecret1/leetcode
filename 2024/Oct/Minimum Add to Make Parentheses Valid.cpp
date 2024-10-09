class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stk;
        for(char ch : s) {
            if(ch == ')') {
                if(stk.size() && stk.top() == '(') stk.pop();
                else stk.push(ch);
            }
            else stk.push(ch);
        }
        return stk.size();
    }
};

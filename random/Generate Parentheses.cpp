class Solution {
public:
    
    vector<string> answer;
    
    void Recurs(string &str, int open , int close, int n) {
        
        if(open == n / 2 && close == n / 2 && isValid(str)) {
            answer.push_back(str);
            return;
        } 
        if(open <= n / 2) {
            str += '(';
            Recurs(str, open + 1, close, n);
            str.pop_back();
        }
        if(close < open) {
            str += ')';
            Recurs(str, open, close + 1, n);
            str.pop_back();
        }
    }

    bool isValid(string str) {
        stack<char> stk;
        for(char ch : str) {
            if(ch == ')') {
                if(stk.top() == ')') return false;
                else stk.pop();
            }
            else {
                stk.push(ch);
            }
        } 
        return true;
    }

    vector<string> generateParenthesis(int n) {
        string str = "";
        n *= 2;
        str += '(';
        Recurs(str, 1, 0, n); 
        return answer;
    }
};

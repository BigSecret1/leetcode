class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        int cnt = 2;
        string curStr = "1";
        while(cnt <= n) {
            curStr = ans;
            ans = NewStr(curStr);
            cnt++;
        }
        return ans;
    }
    
    string NewStr(string str) {
        int cnt = 1;
        string ans = "";
        for(int i = 1; i < str.size(); ++i) {
            if(str[i] == str[i - 1]) cnt++;
            else {
                ans += to_string(cnt);
                ans += str[i - 1];
                cnt = 1;
            }
        }
        ans += to_string(cnt);
        ans += str.back();
        return ans;
    }
};


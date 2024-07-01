class Solution {
public:
    string reverseWords(string s) {
        string str = "";
        string ans = "";
        for(auto it : s) {
            str += it;
            if(it == ' ') {
                reverse(str.begin(), str.end());
                ans += str;
                str = "";
            }
        }
        ans.erase(0, 1);
        if(str.size()) {
            reverse(str.begin(), str.end());
            if(ans.size()) ans += ' ';
            ans += str;
        }
        return ans;
    }
};

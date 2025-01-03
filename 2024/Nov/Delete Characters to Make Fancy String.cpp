class Solution {
public:
    string makeFancyString(string s) {
        string answer = "";
        int cnt = 1;
        int n = s.size();
        if(n == 0) return s;
        answer += s[0];
        for(int i = 1; i < n; ++i) {
            if(s[i] == s[i - 1]) {
                cnt++;
                if(cnt >= 3) continue;
                else answer += s[i];
            }
            else {
                cnt = 1;
                answer += s[i];
            }
        }
        return answer;
    }
};

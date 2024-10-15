class Solution {
public:
    long long minimumSteps(string s) {
        long long answer = 0, cnt = 0;
        reverse(s.begin(), s.end());
        for(auto it : s) {
            if(it == '0') cnt++;
            else answer += cnt;
        }
        return answer;
    }
};

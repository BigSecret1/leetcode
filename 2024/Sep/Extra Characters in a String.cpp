class Solution {
public:
    set<string> st;
    vector<int> dp;
    int minExtraChar(string s, vector<string>& dictionary) {
    for(auto it : dictionary) st.insert(it);
    int n = s.size() + 1;
    dp.resize(n, INT_MIN);
    Recurs(0, n, s);
    return dp[0];
    }

    int Recurs(int i, int n, string s) {
         if(i == n) return 0; 
         if(dp[i] != INT_MIN) return dp[i];
         int answer = Recurs(i + 1, n, s) + 1;
         for(int start = i; start < n; ++start) {
            string str = s.substr(i, start - i + 1);
            if(st.count(str)) {
                answer = min(answer, Recurs(start + 1, n, s));
            }
         }
         return dp[i] = answer;
    }
};

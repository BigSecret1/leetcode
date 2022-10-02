class Solution {
public:
    int numDecodings(string s) {
		if(s[0] == '0') return 0;
		int n = s.size();
		if(n == 1) return 1;
        vector<int> dp(n, 0);
        dp[0] = 1;
        for(int i = 1; i < n; ++i) {
			bool res = Check(s[i - 1], s[i]);
			if(s[i] != '0') {
				dp[i] = dp[i - 1];
				if(res) {
					dp[i] += (i - 2 >= 0 ? dp[i - 2] : 1);
					}
				}
				else {
					if(res) {
					dp[i] += (i - 2 >= 0 ? dp[i - 2] : 1);
					 }
					 else return 0;
					}
			}
			for(auto it : dp) cout << it << " "; cout << endl;
			return dp[n - 1];
    }
    bool Check(char a, char b) {
		int ans = a - '0';
		if(ans == 0) return false;
		ans = ans * 10 + (b - '0');
		if(ans < 27 && ans) return true;
		return false;
		}
};


	

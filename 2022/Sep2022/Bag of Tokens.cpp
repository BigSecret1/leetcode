class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
		int n = tokens.size();
		if(n == 0) return 0;
     vector<int> prefix(n, 0);
     sort(tokens.begin(), tokens.end());
     for(int i = 0; i < n; ++i) {
		 prefix[i] = tokens[i];
		 if(i) prefix[i] += prefix[i - 1];
		 }
		 int ans = 0;
		 for(int i = 0; i < prefix.size(); ++i) {
			 if(prefix[i] <= power) ans++;
			 else break;
			 }
			 int i = 0, j = n - 1;
			 int score = 0;
			 while(i < j) {
				 while(i <= j && power >= tokens[i]) power -= tokens[i], score++, i++;
				 ans = max(ans, score);
				 while(j >= i && score && power < tokens[i]) score--, power += tokens[j], j--;
				 //cout << power << endl;
				 if(i < n && power < tokens[i]) break;
				 ans = max(ans, score);
				 }
				 return ans;
    }
};



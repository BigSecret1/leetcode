class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
		int n1 = nums1.size(), n2 = nums2.size();
		int dp[n1][n2];
		int ans = 0;
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i < n1; ++i) {
			for(int j = 0; j < n2; ++j) {
				if(nums1[i] == nums2[j]) {
					if(i - 1 >= 0 && j - 1 >= 0) {
						dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
						}
						else dp[i][j] = 1;
					}
					ans = max(ans, dp[i][j]);
				}
			}
			//for(int i = 0; i < n1; ++i) {
				//for(int j = 0; j < n2; ++j) {
					//cout << dp[i][j] << " ";
					//}
					//cout << endl;
				//}
			
			return ans;
    }
};


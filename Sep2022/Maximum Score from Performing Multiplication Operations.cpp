class Solution {
public:
    int m, n;
    vector<vector<int>> dp;
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        m = multipliers.size();
        n = nums.size();	
        dp.resize(m + 10, vector<int>(m + 10, INT_MIN));
        return Recurs(0, n - 1, 0, nums, multipliers);
    }
    
    int Recurs(int l, int r, int k, vector<int> &nums, vector<int> &multi) {
        if(l + n - r > m || k >= m) return 0;
        if(dp[l][n - r - 1] != INT_MIN) return dp[l][n - r - 1];
        return dp[l][n - r - 1] = max(multi[k] * nums[l] + Recurs(l + 1, r, k + 1, nums, multi), multi[k] * nums[r] + Recurs(l, r - 1, k + 1, nums, multi));
    }
};



	

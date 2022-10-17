class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
     vector<int> arr;
        arr = jobDifficulty;
        int n = arr.size();
        const int mxN = 1e6;
        if(d > n) return -1;
        vector<vector<int>> dp(n + 100, vector<int>(d + 10, mxN));
        dp[0][1] = arr[0];
        dp[0][0] = 0;
        int mx = arr[0];
        int f = arr[0];
        for(int i = 1; i < n; ++i) {
             f = max(f,arr[i]);
            mx = arr[i];
            dp[i][0] = 0;
            for(int j = i; j > 0; --j) {
                mx = max(mx, arr[j]);
                int val = mx;
                for(int k = 0; k < d; ++k) {
                    if(k == 0) val = f;
                    else val = mx;
                    dp[i][k + 1] = min(dp[i][k + 1], dp[j - 1][k] + val);
                }
            }
        }
        return dp[n - 1][d];
    }
};

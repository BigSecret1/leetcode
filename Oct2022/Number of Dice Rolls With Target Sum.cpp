class Solution {
public:
    long long mod = 1e9 + 7;
    int K = 0;
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<long long>> dp(target + 2, vector<long long> (n + 1, -1));
        K = k;
        return Solve(n, target, 0, dp, 0);
    }
    
    int Solve(int n, int target, int sum, vector<vector<long long>> &dp, int cnt) {
        if(n == 0) {
            if(sum == target) return 1;
            else return 0;
        }
        if(sum > target) return 0;
        if(dp[sum][cnt] != -1) return (dp[sum][cnt] % mod);
        long long ans = 0;
        for(int i = 1; i <= K; ++i) {
            ans += Solve(n - 1, target, sum + i, dp, cnt + 1);
            ans %= mod;
        }
        return dp[sum][cnt] = (ans % mod);
    }
};


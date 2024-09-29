class Solution {
public:
    vector<vector<vector<int>>> dp;
    long long mod = 1e9 + 7;

    int Recurs(int m, int n, int i, int j, int maxMove) {
        if(i >= m || i < 0) return 1;
        if(j >= n || j < 0) return 1;
        if(maxMove == 0) return 0;
        if(dp[i][j][maxMove] != -1) return dp[i][j][maxMove];
        long long answer = 0;
        answer = (answer + Recurs(m, n, i, j + 1, maxMove - 1)) % mod;
        answer = (answer + Recurs(m,n, i + 1, j, maxMove - 1)) % mod;
        answer = (answer + Recurs(m, n, i, j - 1, maxMove - 1)) % mod;
        answer = (answer + Recurs(m, n, i - 1, j, maxMove - 1)) % mod;
        return dp[i][j][maxMove] = (answer % mod);
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        dp.resize(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        return Recurs(m, n, startRow, startColumn, maxMove);
    }
};

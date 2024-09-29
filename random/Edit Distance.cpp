class Solution {
public:

    vector<vector<int>> dp; 
    int n, m;
    int Recurs(string a, string b, int i, int j) {
        if(i >= n) return m - j; 
        if(j >= m) return n - i;
        if(dp[i][j] != -1) return dp[i][j];
        int answer = 0;
        if(a[i] == b[j]) {
            dp[i][j] = Recurs(a, b, i + 1, j + 1);
            return dp[i][j];
        }
        int f = 1 + Recurs(a, b, i, j + 1);
        int s = 1 + Recurs(a, b, i + 1, j);
        int t = 1 + Recurs(a, b, i + 1, j + 1);
        answer = min({f, s, t});
        return dp[i][j] = answer;
    }
    int minDistance(string word1, string word2) {
    n = word1.size();
    m = word2.size();
    dp.resize(n, vector<int>(m, -1));
    Recurs(word1, word2, 0, 0);
    if(n && m) return dp[0][0];
    return max(n, m);
    }
};

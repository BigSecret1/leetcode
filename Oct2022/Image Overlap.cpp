class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int ans = 0;
        int n = img1.size();
        for(int i = -n; i <= n; ++i) {
            for(int j = -n; j <= n; ++j) {
                ans = max(ans, Check(img1, img2, i, j));
            }
        }
        return ans;
    }
    
    int Check(vector<vector<int>> &a, vector<vector<int>> &b, int x, int y) {
        int cnt = 0;
        int n = a.size();
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(i + x < n && i + x >= 0 && j + y >= 0 && j + y < n && a[i][j] == 1 && b[i + x][j + y] == 1) cnt++;
            }
        }
        return cnt;
    }
    
};


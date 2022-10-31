class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        bool ok = true;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(i - 1 >= 0 && j - 1 >= 0) {
                    if(matrix[i - 1][j - 1] != matrix[i][j]) ok = false;
                }
            }
        }
        return ok;
    }
};


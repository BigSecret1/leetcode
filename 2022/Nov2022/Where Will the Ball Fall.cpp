class Solution {   
public:
    vector<int> findBall(vector<vector<int>>& grid) {
       vector<int> answer;
        int n = grid.size();
        int m = grid[0].size();
        answer.resize(m, -1);
       for(int j = 0; j < m; ++j) {
           int r = 0, c = j;
           while(true) {
               if(c - 1 < 0 && grid[r][c] == -1) break;
               if(c + 1 >= m && grid[r][c] == 1) break;
               if(grid[r][c] == 1 && grid[r][c + 1] == -1) break;
               if(grid[r][c] == -1 && grid[r][c - 1] == 1) break;
               if(grid[r][c] == 1) r++, c++;
                else if(grid[r][c] == -1) r++, c--;
                if(r >= n) {
                    c = max(c, 0);
                    c = min(c, m - 1);
                    answer[j] = c;
                    break;
                }
           }
       }
        return answer;
    }
};


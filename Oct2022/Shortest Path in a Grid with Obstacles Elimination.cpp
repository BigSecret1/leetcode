class Solution {
public:
    int n, m;
    vector<vector<int>> dist;
    int shortestPath(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        dist.resize(n, vector<int> (m, -1));
        return BFS(grid, k);
    }
    
    int BFS(vector<vector<int>> &grid, int k) {
		int dx[4] = {1, -1, 0, 0};
		int dy[4] = {0, 0, 1, -1};
		queue<vector<int>> q;
		vector<int> temp = {0, 0, k, 0};
        q.push(temp);
		while(q.size()) {
			auto it = q.front();
			q.pop();
			int r = it[0];
			int c = it[1];
			int cnt = it[2];
			int ans = it[3];
            // cout <<" r : " << r << " c : " << c << " cnt : " << cnt << " ans : " << ans << endl;
			if(r >= n || c >= m) continue;
			if(r == n - 1 &&  c == m - 1 && cnt >= 0) {
				return ans;
				}
				if(grid[r][c]) {
					if(cnt) cnt--;
					else continue;
					}
				for(int i = 0; i < 4; ++i) {
					if(r + dx[i] >= 0 && r + dx[i] < n && c + dy[i] >= 0 && c + dy[i] < m) {
						int x = r + dx[i];
                        int y = c + dy[i];
                        vector<int> temp = {r + dx[i], c + dy[i], cnt, ans + 1};
						if(cnt > dist[x][y]) {
                            dist[x][y] = cnt;
                            q.push(temp);
                          }
						}
					}
			}
			return -1;
		}
};


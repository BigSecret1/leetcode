class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        multiset<int> mst;
        vector<pair<int, int>> vp;
        for(auto it : buildings) {
			vp.push_back({it[0], -it[2]});
			vp.push_back({it[1], it[2]});
			}
			sort(vp.begin(), vp.end());
			vector<vector<int>> ans;
			int n = vp.size();
			mst.insert(0);
			for(int i = 0; i < n; ++i) {
				if(vp[i].second > 0) {
					auto it = mst.lower_bound(vp[i].second);
					int val = vp[i].second;
					if(it != mst.end()) mst.erase(it);
					  int mx = *mst.rbegin();
					if(val > mx) ans.push_back({vp[i].first, mx});
					}
					else  {
						 int val = -vp[i].second;
						int mx = *mst.rbegin();
						if(val > mx) {
							ans.push_back({vp[i].first, val});
							}
							mst.insert(val);
					}
			}
				return ans;
    }
};


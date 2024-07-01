class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        vector<pair<int, int>> v;
        for(auto it : properties) {
			v.push_back({it[0], it[1]});
			}
			int n = v.size();
			sort(v.begin(), v.end());
			vector<int> suffix(n, 0);
			suffix[n - 1] = v.back().second;
			int ans = 0;
			for(int i = n - 2; i >= 0; --i) {
				pair<int, int> p = {v[i].first + 1, -1};
				int idx = lower_bound(v.begin(), v.end(),p) - v.begin();
				if(idx == v.size()) {
					suffix[i] = max(v[i].second, suffix[i + 1]);
					continue;
					}
					if(suffix[idx] > v[i].second) ans++;
					suffix[i] = max(v[i].second, suffix[i + 1]);					
				}
				return ans;
    }
};

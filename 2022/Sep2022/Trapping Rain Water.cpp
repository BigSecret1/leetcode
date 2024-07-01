class Solution {
public:
    int trap(vector<int>& height) {
		int n = height.size();
		vector<int> prefix(n, 0), suffix(n, 0);
		for(int i = 0; i < n; ++i) {
			prefix[i] = height[i];
			if(i) prefix[i] = max(prefix[i - 1], prefix[i]);
			}
			for(int i = n - 1; i >= 0; --i) {
				suffix[i] = height[i];
				if(i + 1 < n) suffix[i] = max(suffix[i], suffix[i + 1]);
				}
				int ans = 0;
				for(int i = 0; i < n; ++i) {
					int mn = min(prefix[i], suffix[i]);
					ans += abs(mn - height[i]);
					}
					return ans;
    }
};

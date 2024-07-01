class Solution {
public:
	int st[400000 + 100];
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
		long long ans = 0, sum = 0;
		long long  mod = 1e9 + 7;
		vector<pair<long long, long long>> v;
		for(int i = 0; i < n; ++i) {
			v.push_back({efficiency[i], speed[i]});
			}
			sort(v.rbegin(), v.rend());
			priority_queue<int, vector<int> , greater<int> > pq;
			for(int i = 0; i < n; ++i) {
				if(pq.size() == k) sum -= pq.top(), pq.pop();
				 pq.push(v[i].second);
				sum += v[i].second;
				long long val = sum, mn = v[i].first;
				val *= mn;
				ans = max(ans, val);
				}
			return (ans % mod);
    }	
    
		
};




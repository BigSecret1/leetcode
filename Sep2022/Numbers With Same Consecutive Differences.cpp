class Solution {
public:
	vector<int> ans;
    vector<int> numsSameConsecDiff(int n, int k) {
		vector<int> v;
		Recurs(v, 0, n, k);
    return ans;
    }
    
    void Recurs(vector<int> num, int sz, int n, int k) {
		if(sz == n) {
			return;
			}
			for(int i = 0; i < 10 && num.size() < n; ++i) {
			    if(num.size() == 0 && i == 0) continue;
			    if(sz == 0) num.push_back(i), Recurs(num, sz + 1, n, k), num.pop_back();
			    else {
					if(abs(num.back() - i) == k) {
						num.push_back(i);
						if(sz + 1 == n) {
							int x = 0;
							for(auto it : num) x = x * 10 + it;
							ans.push_back(x);
							}
						Recurs(num, sz + 1, n, k);
						num.pop_back();
						}
					}
				}
		}
};

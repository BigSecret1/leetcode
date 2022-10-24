class Solution {
public:
    int maxLength(vector<string>& arr) {
		int n = arr.size();
		int answer = 0;
		for(int i = 0; i < (1 << n); ++i) {
			vector<int> cnt(26, 0);
			string str = "";
			for(int j = 0; j < n; ++j) {
				if(i & (1 << j)) {
					str += arr[j];
					}
				}
				bool ok = true;
				for(char c : str) {
					if(cnt[c - 'a']) {
						ok = false;
						break;
						}
						else cnt[c - 'a'] = 1;
					}
					if(ok) answer = max(answer, (int)str.size());
			}
			return answer;
    }
};


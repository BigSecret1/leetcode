class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> mp;
        int n = words.size();
        vector<int> v(2);
        for(int i = 0; i < n; ++i) mp[words[i]] = i + 1;
        set<vector<int>> ans;
        vector<vector<int>> finalV;
        for(int i = 0; i < n; ++i) {
			string str = words[i];
			if(str == "") {
				for(int j = 0; j < n; ++j) {
					if(i == j) continue;
					if(IsOk(words[j])) {
						v[0] = i;
						v[1] = j;
						ans.insert(v);
						swap(v[0], v[1]);
						ans.insert(v);
						}
					}
					continue;
				}
			string b = str;
				reverse(b.begin(), b.end());
				if(mp.find(b) != mp.end() && mp[b] != i + 1) v[0] = i, v[1] = mp[b] - 1, ans.insert(v);
			//cout << str << " " << b << endl;
			string org = str;
			string remain = str;
			for(int j = 0; j < 2; ++j) {
				if(j) reverse(str.begin(), str.end());
				string check = "";
				remain = str;
				for(int k = 0; k < str.size(); ++k) {
					check += str[k];
					remain.erase(0, 1);
					if(IsOk(check)) {
						if(j == 0) reverse(remain.begin(), remain.end());
						//cout << str << " " << remain << endl;
						//cout << str << " " << remain << " " << mp[remain] << endl;
						//cout << str << " " << remain << " " << 
						if(mp.find(remain) != mp.end() && mp[remain] != i + 1) {
							v[0] = i;
							v[1] = mp[remain] - 1;
							if(j == 0) reverse(v.begin(), v.end());
							//cout << i << " " << mp[remain] - 1 << endl;
							ans.insert(v);
						   }
						if(j == 0) reverse(remain.begin(), remain.end());
						}
					}
				}
			}
			for(auto it : ans) finalV.push_back(it);
			return finalV;
    }	
    
    bool IsOk(string &str) {
		if(str.size() == 0) return false;
		//cout << "str : " << str << endl;
		int n = str.size();
		for(int i = 0; i < n / 2; ++i) if(str[i] != str[n - i - 1]) return false;
		return true;
		}
};


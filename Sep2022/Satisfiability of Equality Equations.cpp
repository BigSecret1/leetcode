class Solution {
public:
	int parent[50];
    bool equationsPossible(vector<string>& equations) {
		memset(parent, 0, sizeof(parent));
		for(int i = 1; i <= 26; ++i) parent[i] = i;
		
		for(auto it : equations) {
			int f = it[0] - 'a' + 1;
			int s = it[3] - 'a' + 1;
			string str = "";
			str += it[1];
			str += it[2];
			if(str == "==") {
				Union(f, s);
				}
			}
			bool ok = true;
			for(auto it : equations) {
			int f = it[0] - 'a' + 1;
			int s = it[3] - 'a' + 1;
			string str = "";
			str += it[1];
			str += it[2];
			if(str == "!=") {
				if(Find(f) == Find(s)) ok = false;
				}
			}
			return ok;
    }
    
	int Find(int v) {
		if(parent[v] == v) return v;
		return (parent[v] = Find(parent[v]));
		}
		
	void Union(int a, int b) {
		a = Find(a);
		b = Find(b);
		if(a != b) {
			parent[b] = a;
			}
		}
};


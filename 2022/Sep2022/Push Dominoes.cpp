class Solution {
public:
    string pushDominoes(string dominoes) {
        string s = dominoes;
        string ans = "";
        int n = s.size();
        ans = s;
        if(dominoes.size() == 0) return "";
        int r = -1;
        for(int i = 0; i < n; ++i) {
            if(s[i] == 'L') {
                if(r == -1) {
                    for(int j = i - 1; j >= 0 && ans[j] == '.'; --j) ans[j] = 'L';
                }
                else {
                    for(int j = r + 1, k = i - 1l; j < k; ++j, k--) {
                        ans[j] = 'R';
                        ans[k] = 'L';
                    }
                    r = -1;
                }
            }
            else if(s[i] == 'R') {
                if(r != -1) for(int j = r + 1; j < i; ++j) ans[j] = 'R';
                r = i;
            }
        }
        if(r != -1) for(int j = r + 1; j < n; ++j) ans[j] = 'R';
        return ans;
    }
};

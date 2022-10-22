class Solution {
public:
    unordered_map<char, int> mp1, mp2;
    bool Check() {
        for(char c = 'A'; c <= 'Z'; ++c) {
            if(mp1[c] < mp2[c]) return false;
        }
        for(char c = 'a'; c <= 'z'; ++c) {
            if(mp1[c] < mp2[c]) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int n = s.size();
        int len = n + 1;
        string ans = "";
        int L = 0, R = 0;
        for(auto it : t) mp2[it]++;
        int l = 0, r = 0;
        while(r < n) {
            mp1[s[r]]++;
            while(l <= r && Check()) {
                if(r - l + 1 <= len) {
                    len = r - l + 1;
                    L = l;
                    R = r;
                }
                mp1[s[l]]--;
                l++;
            }
            r++;
        }
        if(len <  n + 1) ans = s.substr(L, R - L + 1);
        return ans;
    }
};


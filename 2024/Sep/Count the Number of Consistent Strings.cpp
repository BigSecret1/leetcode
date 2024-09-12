class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char, bool> mp;
        for(char ch : allowed) {
            mp[ch] = true;
        }
        int n = words.size();
        int answer = 0;
        for(int i = 0; i < n; ++i) {
        bool ok = true;
            for(char ch : words[i]) {
                if(mp.find(ch) == mp.end()) {
                    ok = false;
                }
            }
            if(ok) answer++;
        }
        return answer;
    }
};

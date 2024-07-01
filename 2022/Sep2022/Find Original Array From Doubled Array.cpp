class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        vector<int> ans;
        if(n & 1) return ans;
        map<int, int> mp;
        for(auto it : changed) mp[it]++;
        for(auto it : mp) {
           for(int i = 0; mp[it.first] >= 1 && i < it.second; ++i) {
                if(mp[2 * it.first]) {
                    ans.push_back(it.first);
                    mp[it.first]--;
                    mp[2 * it.first]--;
                }
                else {
                 ans.clear();
                    return ans;
                }
            }
        }
        return ans;
    }
};

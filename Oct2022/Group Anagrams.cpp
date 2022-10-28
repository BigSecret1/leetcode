class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string, int> mp;
        for(auto it : strs) {
            string str = it;
            sort(str.begin(), str.end());
            if(mp.find(str) != mp.end()) ans[mp[str]].push_back(it);
            else {
                vector<string> temp;
                temp.push_back(it);
                ans.push_back(temp);
                mp[str] = ans.size() - 1;
            }
        }
        return ans;
    }
};


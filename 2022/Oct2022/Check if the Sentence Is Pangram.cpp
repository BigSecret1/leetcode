class Solution {
public:
    bool checkIfPangram(string sentence) {
        map<char, int> mp;
        for(auto it : sentence) mp[it]++;
        for(char c = 'a';  c <= 'z'; ++c)  {
            if(mp[c] == 0) return false;
        }
        return true;
    }
};

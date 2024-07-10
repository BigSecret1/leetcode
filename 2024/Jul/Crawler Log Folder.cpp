class Solution {
public:
    int minOperations(vector<string>& logs) {
        map<int, string> mp;
        mp[0] = "../";
        mp[1] = "./";
        int cnt = 0;
        for(auto it : logs) {
            if(it == mp[0]) cnt--;
            else if(it == mp[1]) {}
            else cnt++;
            cnt = max(cnt, 0);
        }
        return cnt; 
    }
};

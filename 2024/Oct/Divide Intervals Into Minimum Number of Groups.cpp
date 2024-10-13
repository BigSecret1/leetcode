class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<pair<int, int>> vp;
        for(auto it : intervals) {
            vp.push_back({it[0], 1});
            vp.push_back({it[1] + 1, -1});
        }
        sort(vp.begin(), vp.end());
        int answer = 1;
        int cnt = 0;
        for(auto it : vp) {
            cnt += it.second;
            answer = max(answer, cnt);
        }
        return answer;
    }
};

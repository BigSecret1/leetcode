class Solution {
public:
    struct comp{
    bool operator() ( pair<int, int> &a, pair<int, int> &b) {
    if (a.first == b.first) {
        return (a.second < b.second);
    } else {
        return (a.first > b.first);
    }
}
    };
    
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int ans = 0;
        int extra = 0;
        vector<pair<int, int>> vp;
        for(int i = 0; i < plantTime.size(); ++i) {
            vp.push_back({growTime[i], plantTime[i]});
        }
        sort(vp.begin(), vp.end(), comp());
        int n = vp.size();
        for(int i = 0; i < n; ++i) {
            int remove = min(extra, vp[i].second);
            int top = vp[i].second;
            int down = vp[i].first;
            top -= remove;
            extra -= remove;
            if(extra < down) ans += down - extra;
            extra = max(extra, down);
            ans += top;
            
        }
    return ans;
    }
};




class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> answer(n, 0);
        vector<pair<int, int>> vp;
        for(int i = 0; i < n; ++i) {
            vp.push_back({arr[i], i});
        }
        sort(vp.begin(), vp.end());
        int rank = 0;
        for(int i = 0; i < n; ++i) {
            if(i == 0) rank++;
            if(i && vp[i - 1].first != vp[i].first) rank++;
            answer[vp[i].second] = rank;
        }
        return answer;
    }
};

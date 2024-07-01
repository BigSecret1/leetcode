class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int, int>> vp;
        for(auto it : arr) {
            vp.push_back({abs(it - x), it});
        }
        sort(vp.begin(), vp.end());
        vector<int> ans;
        for(int i = 0; i < k; ++i) ans.push_back(vp[i].second);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

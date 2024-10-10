class Solution {
public:
    static bool sortNum(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first == b.first ? a.second < b.second : a.first < b.first;
    }

    int maxWidthRamp(vector<int>& nums) {
        vector<pair<int, int>> vp;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            vp.push_back({nums[i], i});
        }

        sort(vp.begin(), vp.end(), sortNum);

        int mn = vp[0].second;
        int answer = 0;

        for (int i = 1; i < n; ++i) {
            answer = max(answer, vp[i].second - mn);
            mn = min(mn, vp[i].second);  // Track the minimum index
        }

        return answer;
    }
};

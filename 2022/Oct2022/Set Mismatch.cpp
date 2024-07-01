class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        vector<int> cnt(n + 1, 0);
        for(auto it : nums) {
            if(cnt[it]) {
                ans.push_back(it);
            }
            else cnt[it]++;
            
        }
        for(int i = 1; i <= n; ++i) if(cnt[i] == 0) ans.push_back(i);
        return ans;
    }
};


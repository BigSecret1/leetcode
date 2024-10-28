class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int answer = -1;
        int n = nums.size();
        int cnt = 0;
        unordered_map<long long, bool> mp;
        int mx = nums[0];
        for(auto it : nums) {
            if(it == 1) cnt++;
            mp[it] = true;
            mx = max(mx, it);
        }
        if(cnt > 1) answer = cnt;
        for(int i = 0; i < n; ++i) {
            long long num = nums[i];
            cnt = 0;
            while(num <= mx) {
                if(mp[num]) cnt++;
                else break;
                num *= num;
            }
            if(cnt > 1) answer = max(answer, cnt);
        }
        return answer;
    }
};

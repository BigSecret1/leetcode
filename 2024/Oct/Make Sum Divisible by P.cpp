class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        unordered_map<int, int> mp;
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            sum += (nums[i] % p);
            sum %= p;
        }
        sum %= p;
        int answer = INT_MAX;
        mp[0] = -1;
        if(sum == 0) return 0;
        long long curr = 0;
        for(int i = 0; i < n; ++i) {
            curr = (nums[i] % p + curr) % p;
            int needed = (curr - sum + p) % p;
            if(mp.find(needed) != mp.end()) {
                answer = min(answer, i - mp[needed]);
            }
                        mp[curr] = i;
        }
        if(answer == INT_MAX || answer == n) answer = -1;
        return answer;
    }
};

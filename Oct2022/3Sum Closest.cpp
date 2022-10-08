class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = 0;
        int diff = INT_MAX;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 2; ++i) {
            int l = i + 1, r = n - 1;
            while(l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                 if(abs(target - sum) <= diff) 
                        diff = abs(target - sum), ans = sum;
                if(sum > target) {
                    r--;
                }
                else if(sum < target) {
                    l++;
                }
                else return sum;
            }
        }
        return ans;
    }
};



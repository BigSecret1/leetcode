class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int sum = 0;
        for(int it : nums) {
            if(it % 2 == 0) sum += it;
        }
        for(auto it : queries) {
            int val = it[0], idx = it[1];
            if(nums[idx] % 2 == 0) sum -= nums[idx];
            nums[idx] +=  val;
            if(nums[idx] % 2 == 0) sum += nums[idx];
            ans.push_back(sum);
        }
        return ans;
    }
};

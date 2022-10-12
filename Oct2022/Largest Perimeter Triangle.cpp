class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        vector<int> arr(n);
        arr = nums;
        sort(arr.begin(), arr.end());
        for(int i = 0; i < n - 2; ++i) {
            if(arr[i] + arr[i + 1] > arr[i + 2]) {
                ans = max(ans, arr[i] + arr[i + 1] + arr[i + 2]);
            }
        }
        return ans;
    }
};

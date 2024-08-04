    class Solution {
    public:
        int mod = 1e9 + 7;
        int rangeSum(vector<int>& nums, int n, int left, int right) {
            vector<long long> sum;
            for(int i = 0; i < n; ++i) {
                long long total = 0;
                for(int j = i; j < n; ++j) {
                total += nums[j]; 
                sum.push_back(total);
                }
            }
            sort(sum.begin(), sum.end());
            long long answer = 0;
            for(int i = left - 1; i < right; ++i) {
                (answer += sum[i]) %= mod;
            }
            return answer;
        }
    };

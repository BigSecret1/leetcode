class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        int sum = 0;
        for(int i = 0; i < n; ++i) {
            sum += chalk[i];
            if(sum > k) return i;
        }
        k = k % sum;
        sum = 0;
        for(int i = 0; i < n; ++i) {
            sum += chalk[i];
            if(sum > k) return i;
        }
        return 0;
    }
};

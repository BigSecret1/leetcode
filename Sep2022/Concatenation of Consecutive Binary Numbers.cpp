class Solution {
public:
    int concatenatedBinary(int n) {
        long long mod = 1e9 + 7;
        string sum = "";
        long long ans = 0;
        long long cnt = 1;
        for(int i = n; i >= 1; --i) {
            int val = i;
            while(val) {
            int x = val % 2;
            if(x) ans += cnt;
            ans %= mod;
            cnt *= 2;
            cnt %= mod;
            val /= 2;
            }
        }
        return ans % mod;
    }
   
};

class Solution {
public:

    double Recurs(double x, long long n) {
     if(n == 0) return 1;
    double answer = 1;
    answer = (n % 2 == 0 ? Recurs(x * x, n / 2) : x * Recurs(x * x, (n - 1) / 2)); 
    return answer;
    }

    double myPow(double x, int n) {
    double answer = Recurs(x, abs(n));
    if(n < 0) return 1 / answer;
    return answer;
    }
    
};

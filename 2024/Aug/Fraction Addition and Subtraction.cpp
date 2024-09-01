class Solution {
public:
    string fractionAddition(string expression) {
        
       vector<int> den, num;
       int n = expression.size();
       for(int i = 0; i < n; ++i) {
        if(i + 1 < n && expression[i + 1] == '/') {
        num.push_back(expression[i] - '0');
        if(i - 1 >= 0 && expression[i - 1] == '-') {
            num.back() = num.back() * -1;
            
         }
          if(expression[i] == '0' && i - 1 >= 0 && expression[i - 1] == '1') {
            num.back() = 10; 
            if(i - 2 >= 0 && expression[i - 2] == '-') num.back() *= -1;
          }
        }
        if(i - 1 >= 0 && expression[i - 1] == '/') {
        den.push_back(expression[i] - '0');
         if(i + 1 < n && expression[i] == '1' && expression[i + 1] == '0') den.back() = den.back() * 10;
         }
          
       }

       
       int gcd = 1;
       for(auto it : den) gcd = Gcd(abs(it), gcd);
       int lcm = den[0];
       for(auto it : den) {
         lcm = (((it  * lcm)) /
                (Gcd(it, lcm)));
       }
       int top = 0;
       for(int i = 0; i < num.size(); ++i) {
        int divide = lcm / den[i];
        top += (num[i] * divide);
       }
       gcd = Gcd(top, lcm);
       top /= gcd;
       lcm /= gcd;
       return (to_string(top) + '/' + to_string(lcm));

    }

    int Gcd(int a, int b) {
        a = abs(a);
        b = abs(b);
        if(a == 0) return b;
        return Gcd(b % a, a);
    }
    
};

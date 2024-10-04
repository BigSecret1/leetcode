class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        long long sum = 0;
        int m = n / 2;
        for(int i = 0; i < n; ++i) {
            long long num = skill[i];
            sum += num;
        }
        if(sum % m) return -1;
        long long need = sum / m;
        long long answer = 0;
        sort(skill.begin(), skill.end());
        for(int i = 0; i < m; ++i) {
            if(skill[i] + skill[n - 1 - i] != need) {
                answer = -1;
                break;
            }
            else {
                long long  a  = skill[i];
                long long b = skill[n - 1 - i];
                answer += (a * b);
            }
        }
        return answer;
    }
};

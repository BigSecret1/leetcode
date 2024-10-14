class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto it : nums) pq.push(it);
        long long answer = 0;
        while(k--) {
            long long num = pq.top();
            pq.pop();
            answer += num;
            num = ceil(num / 3.0);
            pq.push(num);
        }
        return answer;
    }
};

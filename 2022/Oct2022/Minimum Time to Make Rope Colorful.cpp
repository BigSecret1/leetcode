class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        priority_queue <int, vector<int>, greater<int> > pq;
        int cnt = 0;
        pq.push(neededTime[0]);
        for(int i = 1; i < colors.size(); ++i) {
            if(colors[i] == colors[i - 1]) cnt++, pq.push(neededTime[i]);
            else {
                while(cnt) ans += pq.top(), pq.pop(), cnt--;
                pq.pop();
                pq.push(neededTime[i]);
            }
        }
        while(cnt) ans += pq.top(), pq.pop(), cnt--;
        return ans;
    }
};

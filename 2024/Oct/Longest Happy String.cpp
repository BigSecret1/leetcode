class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if(a) pq.push({a, 'a'});
        if(b) pq.push({b, 'b'});
        if(c) pq.push({c, 'c'});
        string answer = "";
        while(pq.size()) {
            auto top = pq.top();
            pq.pop();
            for(int i = 0; i < min(2, top.first); ++i) {
                answer += top.second;
                int sz = answer.size() - 1;
                if(i == 0 && sz - 1 >= 0 && answer[sz - 1] == top.second) {
                    top.first++;
                    break;
                }
            }
            top.first -= 2;
            top.first = max(top.first, 0);
            if(pq.size() == 0) break;
            auto secondTop = pq.top();
            pq.pop();
            answer += secondTop.second;
            secondTop.first--;
            if(secondTop.first) pq.push(secondTop);
            if(top.first) pq.push(top);
        }
        return answer;
    }
};

class Solution {
public:
    
    void Recurs(int num, int n, vector<int> &answer) {
        if(num > n) return;
        answer.push_back(num);
        for(int i = 0; i < 10; ++i) {
            if(num * 10 + i > n) break;
            Recurs(num * 10 + i, n, answer);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> answer;
        for(int i = 1; i < 10; ++i)
        Recurs(i, n, answer);
        return answer;
    }
};

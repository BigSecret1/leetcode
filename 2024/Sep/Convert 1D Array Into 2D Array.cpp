class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        
        int sz = original.size();
        vector<vector<int>> answer;
        if(sz != n * m) return answer;
        
        answer.resize(m);
        int cnt = 0;
        for(int i = 0; i < sz; ++i) {
            if(i % n == 0 && i) cnt++;
            answer[cnt].push_back(original[i]);
        }
        return answer;
    }
};

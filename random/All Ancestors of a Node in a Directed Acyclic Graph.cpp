
class Solution {
public:
    vector<vector<int>> edge, answer, finalAnswer;
    vector<int> mark;

    void Dfs(vector<vector<int>> &edge, int node, int ancestor) {
        for(auto it : edge[node]) {
            if(answer[it].size() && answer[it].back() == ancestor) continue;
            answer[it].push_back(ancestor);
            Dfs(edge, it, ancestor);
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        edge.resize(n + 1);
        answer.resize(n);
        finalAnswer = answer;
        mark.resize(n + 1, false);
        int m = edges.size();
        for(int i = 0; i < m; ++i) {
            int first = edges[i][1];
            int second = edges[i][0];
            edge[second].push_back(first);
        }
        for(int i = 0; i < n; ++i) {
            Dfs(edge, i, i);
        }
        return answer;
    }
};




class Solution {
public:
    vector<vector<int>> edge;
    stack<int> stk;
    vector<int> mark;
    
    bool CheckCycle(int node) {
        mark[node] = 1;
        for(auto it : edge[node]) {
            if(mark[it] == 1) return true;
            if(mark[it] == 0 && CheckCycle(it)) return true;
        }
        mark[node] = 2;
        return false;
    }

    void Dfs(int node) {
        if(mark[node]) return;
        mark[node] = true;
        for(auto it : edge[node]) {
            if(mark[it] == 1) continue;
            Dfs(it);
        } 
        stk.push(node);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        edge.resize(n);
        mark.resize(n, false);
        int m = prerequisites.size();
        for(int i = 0; i < m; ++i) {
            int to = prerequisites[i][0];
            int from = prerequisites[i][1];
            edge[from].push_back(to);
        }
        for(int i = 0; i < n; ++i) {
            if(mark[i] == 0 && CheckCycle(i)) return {};
        }
        for(int i = 0; i < n; ++i) mark[i] = 0; 
        for(int i = 0; i < n; ++i) {
            if(mark[i] == false) {
                Dfs(i);
            }
        }
        vector<int> answer;
        while(stk.size()) {
            answer.push_back(stk.top());
            stk.pop();
        }
        return answer;
    }
};

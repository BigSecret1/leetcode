class Solution {
public:

    const int INF = 1000000000;
    vector<vector<pair<int, int>>> adj;

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
    if(source == target) return 0;
        adj.resize(26);
        int n = changed.size();
        adj.resize(n + 10);
        for(int i = 0; i < n; ++i) {
            int from = original[i] - 'a';
            int to = changed[i] - 'a';
            adj[from].push_back({to, cost[i]});
        }
        int m = source.size();
        long long answer = 0;
        vector<vector<int>> minCost(26, vector<int>(26, INF));
        for(int i = 0; i < 26; ++i) {
            vector<int> d, p;
            dijkstra(i, d, p);
            for(int j = 0; j < 26; ++j) {
                if(d.size() > j)minCost[i][j] = d[j];
            }
        }
        for(int i = 0; i < m; ++i) {
            if(source[i] == target[i]) continue;
            int l = source[i] - 'a';
            int r = target[i] - 'a';
            if(minCost[l][r] == INF) return -1;
            long long distance = minCost[l][r];
            answer += distance; 
        }
        //if(answer == 0) return -1;
        return answer;
    }

    
    void dijkstra(int s, vector<int> & d, vector<int> & p) {
        int n = adj.size();
        n = 26;
        d.assign(n, INF);
        p.assign(n, -1);

        d[s] = 0;
        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> q;
        q.push({0, s});
        while (!q.empty()) {
            int v = q.top().second;
            int d_v = q.top().first;
            q.pop();
            if (d_v != d[v])
                continue;

            for (auto edge : adj[v]) {
                int to = edge.first;
                int len = edge.second;

                if (d[v] + len < d[to]) {
                    d[to] = d[v] + len;
                    p[to] = v;
                    q.push({d[to], to});
                }
            }
        }
    }

};

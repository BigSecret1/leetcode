class Solution {
public:
    vector<int> mark;
    map<pair<int, int>, double> mp;
    double answer;
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
    
    answer = INT_MIN;
    vector<vector<pair<int, double>>> edge(n);
    mark.resize(n, false);
    int m = edges.size();
    for(int i = 0; i < m; ++i) {
        int u = edges[i][0];
        int v = edges[i][1];
        edge[u].push_back({v, succProb[i]});
        edge[v].push_back({u, succProb[i]});
        }
     vector<double> dist(n, INT_MIN);
     Djk(edge, start_node, n, dist);
     answer = dist[end_node];
     if(answer == INT_MIN) answer = 0;
     return answer;
    }

    void Djk(vector<vector<pair<int, double>>> &edge, int src, int n, vector<double> &dist) {

    priority_queue<pair<double, int>> pq;

    pq.push(make_pair(1.0, src));
    dist[src] = 1.0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto &neighbor : edge[u]) {
            int v = neighbor.first;
            double weight = neighbor.second;

            if (dist[v] < dist[u] * weight) {
                dist[v] = dist[u] * weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
 }
};

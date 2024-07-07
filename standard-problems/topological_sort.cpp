void Dfs(int node) {
    if(mark[node]) return;
    mark[node] = true;
    for(auto it : edge[node]) {
        if(mark[it] == 1) continue;
        Dfs(it);
    } 
    stk.push(node);
}


for(int i = 0; i < n; ++i) {
    if(mark[i] == false) Dfs(i);
}

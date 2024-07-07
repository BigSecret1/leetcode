bool CheckCycle(int node) {
    mark[node] = 1;
    for(auto it : edge[node]) {
        if(mark[it] == 1) return true;
        if(mark[it] == 0 && CheckCycle(it)) return true;
    }
    mark[node] = 2;
    return false;
}


for(int i = 0; i < n; ++i) {
    if(mark[i] == false) CheckCycle(i);
}

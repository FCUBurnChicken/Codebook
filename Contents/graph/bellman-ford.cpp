void bellman(vector<edge>& edges, vector<int>& dist, int n){
    // n - 1 relax
    for(int i = 1; i < n; i++){
        for(edge e : edges){
            int u = e.start, v = e.end, d = e.dist;
            if(dist[u] == INF) continue;
            dist[v] = min(dist[v], d + dist[u]);
        }
    }

    // 偵測負權迴路
    for(edge e : edges){
        int u = e.start, v = e.end, d = e.dist;
        if(dist[u] == INF) continue;
        if(dist[v] > dist[v] + d){
            printf("It is contained negative cycle.\n");
            break;
        }
    }
}
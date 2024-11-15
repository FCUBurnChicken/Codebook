struct edge{
    int u, v, c, f;
    edge(int u, int v, int c, int f):u(u), v(v), c(c), f(f){}
};
vector<edge>e;
vector<int> G[maxn];
int level[maxn]; // 紀錄每個點的層數
int iter[maxn]; // 目前弧優化
int m;
void init(int n){
    for(int i = 0; i <= n; i++)G[i].clear();
    e.clear();
}
void addedge(int u, int v, int c){
    e.push_back(edge(u, v, c, 0));
    e.push_back(edge(v, u, 0, 0));
    m = e.size();
    G[u].push_back(m - 2);
    G[v].push_back(m - 1);
}

void BFS(int s){
    memset(level, -1, sizeof(level));
    queue<int> q;
    level[s] = 0;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v = 0; v < G[u].size(); v++){
            edge& now = e[G[u][v]];
            if(now.c > now.f && level[now.v] < 0){
                level[now.v] = level[u] + 1;
                q.push(now.v);
            }
        }
    }
}

// 尋找增廣路徑
int dfs(int u, int t, int f){
    if(u == t) return f;

    // 用 iter 表示每個節點目前的弧，防止多次遍歷
    for(int &v = iter[u]; v < G[u].size(); v++){
        edge &now = e[G[u][v]];

        // now.c - now.f > 0 表示此路未清空
        // level[u] < level[now.v] 表示這條路是最短路
        if(now.c - now.f > 0 && level[u] < level[now.v]) {
            int d = dfs(now.v, t, min(f, now.c - now.f));
            if(d > 0) {
                now.f += d; // 正向邊流量 +d
                e[G[u][v] ^ 1].f -= d; // 反向邊 -d
                return d;
            }
        }
    }
    return 0;
}

int Maxflow(int s, int t){
    int flow = 0;
    for(;;) {
        BFS(s);
        // 殘餘的路線達不到 t，增廣路徑不存在
        if(level[t] < 0) return flow; 
        memset(iter, 0, sizeof(iter));
        int f;
        while((f = dfs(s, t, INF)) > 0) flow += f;
    }
    return flow;
}
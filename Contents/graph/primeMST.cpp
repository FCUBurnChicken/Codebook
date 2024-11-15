// O(N^2) 類似 dijkstra
void prim(){
    memset(dis, 0x3f, sizeof dis); 
    dis[1] = 0; st[1] = 1;  // 抓個初始點
    int ans = 0; // 記錄邊上權重
    
    for (int i = 0; i < n; i ++ ){
        int t = -1;
        for (int j = 1; j <= n; j ++ ){
            if (!st[j] && (t == -1 || dis[j] < dis[t])) t = j; // 尋找距離最近的節點
        }
        
        if (dis[t] == INF) { // 最短距離為 INF，則不存在 MST
            puts("impossible");
            return;
        }
        
        ans += dis[t];
        st[t] = 1; // 將節點加入 MST
        
        for (int j = 1; j <= n; j ++ ){
            if (!st[j]){
                dis[j] = min(dis[j], dis[t] + g[t][j]); // 更新其他節點到 MST 的距離
            }
        }
    }
    
    return ans;
}
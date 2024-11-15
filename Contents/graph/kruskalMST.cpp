struct Edge{
    int a, b, c;
}edge[M];

int find(int x) {
    return x == p[x] ? x : p[x] = find(p[x]);
}

// 要先按照邊權重升序
void kruskal(){
    int ans = 0;
    for (int i = 0; i < m; i ++ ){
        int a = edge[i].a, b = edge[i].b, c = edge[i].c;
        
        int pa = find(a), pb = find(b); // 找節點 A 與節點 B 所屬的集合
        
        if (pa != pb){  // 若為不同集合，就合併
            p[pb] = pa;
            cnt ++;
            ans += c;
        }
    }
    
    if (cnt == n - 1) cout << ans << endl; // 邊的數量不為 n - 1，則沒有 MST
    else puts("impossible");
}
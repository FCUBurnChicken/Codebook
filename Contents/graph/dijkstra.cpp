void dijkstra(ll st){
    vector<ll> dis(n, INF);
    //pll (vetrex, distance)
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({st, 0});
    dis[st] = 0;
    while(!pq.empty()){
        pll now = pq.top();
        pq.pop();
        if(now.ss != dis[now.ff]) continue;
        for(pll i : graph[t.ff]){
            if(dis[now.ff] + i.ss < dis[i.ff]){
                dis[i.ff] =  now.ss + i.ss;
                pq.push({i.ff, dis[i.ff]});
            }
        }
    }
}
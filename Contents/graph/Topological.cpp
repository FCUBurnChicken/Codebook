//此處為建立 Adjacency List 和每個節點的入度點數量
vector<vector<int>> make(vector<Edge>& nodes, int n){
	vector<vector<int>> graph(n + 1);
	vector<int> indegree(n, 0);
	for(auto node : nodes){
		graph[node.src].pb(node.des);
		indegree[node.des] ++; //計算入度點
	}
	graph[n] = indegree;
	return graph;
}

// 拓樸排序
vector<int> TolpologicalOrder(vector<vector<int>> graph){
	int n = graph.size();
	queue<int> q;
	vector<int> result;
	for(int i=0; i<graph[n - 1].size(); i++){
		if(!graph[n - 1][i]) q.push(i);
	}
	while(!q.empty()){
		int cnt = q.front();
		result.pb(cnt);
		q.pop();
		for(int i=0; i<graph[cnt].size(); i++){
				graph[n - 1][graph[cnt][i]]--;
				if(!graph[n - 1][graph[cnt][i]]) q.push(graph[cnt][i]);
		}
	}

    //偵測循環
	for(auto i : graph[n-1]) if(i) return {};

	return result;
}
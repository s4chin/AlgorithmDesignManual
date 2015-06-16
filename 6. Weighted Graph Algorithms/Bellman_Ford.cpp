vi dist(V, INF); 
dist[s] = 0;

for (int i = 0; i < V; i++)
	for (int u = 0; u < V; u++)
		for (int j = 0; j < (int)AdjList[u].size(); j++) {
			ii v = AdjList[u][j];
			dist[v.first] = min(dist[v.first], dist[u] + v.second);
		}

// for checking if graph has negative cycle
bool hasNegativeCycle = false;
for (int u = 0; u < V; u++)
	for (int j = 0; j < (int)AdjList[u].size(); j++) {
		ii v = AdjList[u][j];
		if (dist[v.first] > dist[u] + v.second)
			hasNegativeCycle = true;
	}
printf("Negative Cycle Exist? %s\n", hasNegativeCycle ? "Yes" : "No");


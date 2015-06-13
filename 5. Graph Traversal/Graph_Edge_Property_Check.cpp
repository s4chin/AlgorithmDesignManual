void graphCheck(int u) {
	dfs_num[u] = EXPLORED;
	for (int j = 0; j < (int)AdjList[u].size(); j++) {
		ii v = AdjList[u][j];
		if (dfs_num[v.first] == UNVISITED) {
			dfs_parent[v.first] = u;
			graphCheck(v.first);
		}
		else if (dfs_num[v.first] == EXPLORED) {
			if (v.first == dfs_parent[u])
				printf(" Two ways (%d, %d)-(%d, %d)\n", u, v.first, v.first, u);
			else
				printf(" Back Edge (%d, %d) (Cycle)\n", u, v.first);
		}
		else if (dfs_num[v.first] == VISITED)
			printf(" Forward/Cross Edge (%d, %d)\n", u, v.first);
	}
	dfs_num[u] = VISITED;
}

// inside int main()
	dfs_num.assign(V, UNVISITED);
	dfs_parent.assign(V, 0);
	for (int i = 0; i < V; i++)
		if (dfs_num[i] == UNVISITED)
			printf("Component %d:\n", ++numComp), graphCheck(i);

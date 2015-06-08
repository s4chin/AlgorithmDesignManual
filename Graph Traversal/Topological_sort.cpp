vi ts;

void tsort(int u) {
	dfs_num[u] = VISITED;
	for (int j = 0; j < (int)AdjList[u].size(); j++) {
		ii v = AdjList[u][j];
		if (dfs_num[v.first] == UNVISITED)
			tsort(v.first);
	}
	ts.push_back(u);
}

// inside int main()
	ts.clear();
	memset(dfs_num, UNVISITED, sizeof dfs_num);
	for (int i = 0; i < V; i++)
		if (dfs_num[i] == UNVISITED)
			tsort(i);
	// can also call: reverse(ts.begin(), ts.end()); to reverse
	for (int i = (int)ts.size() - 1; i >= 0; i--)
		printf(" %d", ts[i]);
	printf("\n");

// Note that ts stores the sort order in reverse
// Linked List can be used instead of vector to store in correct order
// Queue can also be used to store in correct order, but not used due to obvious reasons
// This lists only 1 order; for all sorts, we have to use backtracking

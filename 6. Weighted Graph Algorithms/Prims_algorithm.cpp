vi taken;
priority_queue<ii> pq;

void process(int vtx) {
	taken[vtx] = 1;
	for (int j = 0; j < (int)AdjList[vtx].size(); j++) {
		ii v = AdjList[vtx][j];
		if(!taken[v.first]) pq.push(ii(-v.second, -v.first));
	}
} // -ve sign to sort order so that least weight comes on top of pq

// inside int main()
	taken.assign(V, 0);
	process(0);
	mst_cost = 0;
	while (!pq.empty()) {
		ii front = pq.top(); pq.pop();
		u = -front.second, w = -front.first;
		if (!taken[u])
			mst_cost += w, process(u); // Add u and see its neighbors
	}
	printf("MST cost = %d (Prim's)\n", mst_cost);


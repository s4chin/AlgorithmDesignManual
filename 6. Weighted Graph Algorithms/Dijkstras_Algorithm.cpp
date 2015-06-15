vi dist(V, INF);
dist[s] = 0;

priority_queue< ii, vector<ii>, greater<ii> > pq;// make a pq of all vertices
pq.push(ii(0, s)); // At start, pq has only one element

while(!pq.empty()) {
	ii front = pq.top(); pq.pop();
	int d = front.first, u = front.second;
	if (d > dist[u]) continue; /* Our Algorithm does not remove the inferior 
	vertices so there may be more than one instances of the same vertex, so this
	check is to take in account only the latest and filter out the outdated*/
	for ( int j = 0; j < (int)AdjList[u].size(); j++) {
		ii v = AdjList[u][j];
		if (dist[u] + v.second < dist[v.first]) { // if v is closer via u only then add it to pq
			dist[v.first] = dist[u] + v.second;
			pq.push(ii(dist[v.first], v.first));
		}
	}
}

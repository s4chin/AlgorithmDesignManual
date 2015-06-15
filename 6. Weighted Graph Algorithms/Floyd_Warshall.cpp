// inside int main()
	// Assuming AdjMat[i][j] stores the weight of edge between i and j
	for (int k = 0; k < V; k++) // loop order is k->i->j
		for (int i = 0; i < V; i++)
			for (int j = 0; j < V; j++)
				AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j])


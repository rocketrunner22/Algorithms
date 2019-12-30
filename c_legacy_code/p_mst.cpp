// STL implementation of Prim's algorithm for MST 
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> p;


void addEdge(vector <pair<int, int> > adj[], int u,
	int v, int wt)
{
	adj[u].push_back(make_pair(v, wt));
	adj[v].push_back(make_pair(u, wt));
}

void primMST(vector<pair<int, int> > adj[], int V)
{
	priority_queue< p, vector <p>, greater<p> > pq;

	int src = 0;
	int count = V;
	
	vector<int> key(V, INT_MAX);

	vector<int> parent(V, -1);

	vector<bool> inMST(V, false);


	pq.push(make_pair(0, src));
	key[src] = 0;
	int loop = 0;
	
	//while (!pq.empty())
	while (count != 0) {
		int u = pq.top().second;
		pq.pop();
		loop++;
		inMST[u] = true; // Include vertex in MST 
		count--;
		// Traverse all adjacent of u 
		for (auto x : adj[u]) {
			int v = x.first;
			int weight = x.second;

			
			if (inMST[v] == false && key[v] > weight) {
				key[v] = weight;
				pq.push(make_pair(key[v], v));
				parent[v] = u;
			}
		}
	}

	for (int i = 1; i < V; ++i)
		printf("%d - %d\n", parent[i], i);
	cout << loop;
}

int main()
{
	int V = 9;
	vector<p > adj[9];

	// making above shown graph 
	addEdge(adj, 0, 1, 4);
	addEdge(adj, 0, 7, 8);
	addEdge(adj, 1, 2, 8);
	addEdge(adj, 1, 7, 11);
	addEdge(adj, 2, 3, 7);
	addEdge(adj, 2, 8, 2);
	addEdge(adj, 2, 5, 4);
	addEdge(adj, 3, 4, 9);
	addEdge(adj, 3, 5, 14);
	addEdge(adj, 4, 5, 10);
	addEdge(adj, 5, 6, 2);
	addEdge(adj, 6, 7, 1);
	addEdge(adj, 6, 8, 6);
	addEdge(adj, 7, 8, 7);

	primMST(adj, V);

	return 0;
}
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 10000
#define INF (1048576)

struct comp {
	bool operator()(const pair<int, int> &a, const pair<int, int> &b) {//have to overload for some reason
		return a.second > b.second;//second is weight
	}
};

priority_queue<pair< int, int >, vector<pair< int, int > >, comp> Q;//datatype, vector datatype, comparator
vector<pair< int, int >> G[MAX];
int D[MAX];
bool F[MAX] = { false };

int main()
{
	int i, u, v, w, sz, nodes, edges, starting, end;
	cout << "Enter the number of vertices and edges: ";
	cin >> nodes >> edges;
	cout << "Enter the edges with weight: <source> <destination> <weight>: \n";
	for (i = 0; i < edges; i++)
	{
		cin >> u >> v >> w;
		G[u].push_back(pair< int, int >(v, w));
		G[v].push_back(pair<int, int>(u, w));//cause you can go both ways
	}
	cout << "Enter the source node: ";
	cin >> starting;
	cout << "Enter target node: ";
	cin >> end;

	for (i = 1; i <= nodes; i++)
		D[i] = INF;
	D[starting] = 0;
	Q.push(pair< int, int >(starting, 0));

	while (!Q.empty())
	{
		u = Q.top().first;
		Q.pop();
		if (F[u])//cause its true if 1
			continue;
		sz = G[u].size();
		for (i = 0; i < sz; i++)
		{
			v = G[u][i].first;
			w = G[u][i].second;
			if (!F[v] && D[u] + w < D[v])
			{
				D[v] = D[u] + w;
				Q.push(pair< int, int >(v, D[v]));
			}
		}
		F[u] = true;
	}
	cout << "Distance to Target Node: " << D[end] << endl;
	return 0;
}
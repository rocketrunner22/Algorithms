#include <iostream>
#include <queue>
#include <vector>
#include <limits>

using namespace std;

struct compare {
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
		return a.second > b.second;//second is weight
	}
};

vector<unsigned int> dijkstras(vector<vector <pair< unsigned int, unsigned int >>>, unsigned int, unsigned int, unsigned int);
void printPath(vector<unsigned int>, unsigned int, unsigned int);

int main() {
	vector<vector <pair< unsigned int, unsigned int >>> graph;
	unsigned int numNodes, numEdges;

	cout << "Enter the number of vertices and edges: ";
	cin >> numNodes >> numEdges;
	
	graph.resize(numEdges);
	
	unsigned int src, dest, weight;
	cout << "Enter the edges with weight: <source> <destination> <weight>: \n";
	
	for (unsigned int i = 0; i < numEdges; i++) {
		cin >> src >> dest >> weight;
		graph[src].push_back(make_pair(dest, weight));
		graph[dest].push_back(make_pair(src, weight));//cause you can go both ways
	}
	
	unsigned int start, end;
	cout << "Enter the source node: ";
	cin >> start;
	cout << "Enter target node: ";
	cin >> end;

	vector<unsigned int> path = dijkstras(graph, numNodes, start, end);
	
	cout << "Best Path to Target Node: " << start << ' ';
	printPath(path, start, end);
	cout << end << endl;
	return 0;
}

vector<unsigned int> dijkstras(vector<vector <pair< unsigned int, unsigned int >>> graph, unsigned int numNodes, unsigned int start, unsigned int end) {
	unsigned int src, dest, weight, size;
	priority_queue<pair< unsigned int, unsigned int >, vector<pair< unsigned int, unsigned int > >, compare> p_queue;//datatype, vector datatype, comparator
	vector<unsigned int> distance(numNodes);//size numNodes
	vector<bool> visited(numNodes, false);
	vector<unsigned int> bestPathToNode(numNodes);

	distance[start] = 0;
	for (unsigned int i = 1; i < numNodes; i++)
		distance[i] = numeric_limits<unsigned int>::max();;
	
	p_queue.push(make_pair(start, 0));
	
	while (!p_queue.empty()) {
		src = p_queue.top().first;
		p_queue.pop();
		if (visited[src])
			continue;
		size = graph[src].size();
		for (unsigned int i = 0; i < size; i++) {
			dest = graph[src][i].first;
			weight = graph[src][i].second;
			if (!visited[dest] && distance[src] + weight < distance[dest]) {
				distance[dest] = distance[src] + weight;
				bestPathToNode[dest] = src;//sets the best path to the node
				p_queue.push(pair< int, int >(dest, distance[dest]));
			}
		}
		visited[src] = true;
	}
	//distance[end] is the distance to the src
	cout << "Distance to Target Node: " << distance[end] << endl;
	return bestPathToNode;
}

void printPath(vector<unsigned int> path, unsigned int start, unsigned int end) {
	if (path[end] == start)
		return;
	printPath(path, start, path[end]);
	cout << path[end] << " ";
	return;
}
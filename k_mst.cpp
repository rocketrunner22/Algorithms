#include <iostream>
#include <fstream>


using namespace std;

struct edge {
	int source, destination, weight;
};

void prnt(bool arr[], struct edge x[], int len, int cost) {
	cout << "S D W MST" << endl;
	for (int i = 0; i < len; i++)
		cout << x[i].source << " "<< x[i].destination << " " <<x[i].weight << "  " << arr[i] << endl;
	cout << endl << "MST: " << cost << endl;
}

int c(const void *p, const void *q) {
	int l = ((struct  edge*)p)->weight;
	int r = ((struct edge *)q)->weight;
	return (l - r);
}

int find(int arry[], int i) {
	if (i == arry[i])
		return i;
	else {
		arry[i] = find(arry, arry[i]);
		return arry[i];
	}
}

void u(int arry[], int x, int y) {
	int a = find(arry, x);
	int b = find(arry, y);
	arry[b] = a;
}

//edge graph[7];
//bool inTree[7] = { false };
//int set[7] = { 0,1,2,3,4,5,6 };
int main() {
	ifstream infile("in.txt");
	int cost = 0;
	int numEdge;
	infile >> numEdge;
	struct edge* graph = (edge*)malloc(numEdge * sizeof(struct edge));
	bool* inTree = (bool*)malloc(numEdge * sizeof(bool));
	int* set = (int*)malloc(numEdge * sizeof(int));
	for (int i = 0; i < numEdge; i++)
		set[i] = i;
	for (int i = 0; i < numEdge; i++) {
		infile >> graph[i].source >> graph[i].destination >> graph[i].weight;
	}
	qsort(graph, sizeof(graph) / sizeof *graph, sizeof(edge), c);
	for (int i = 0; i < numEdge; i++) {
		int x = find(set, graph[i].source);
		int y = find(set, graph[i].destination);
		if (x != y) {
			inTree[i] = true;
			u(set, graph[i].source, graph[i].destination);
			cost += graph[i].weight;
		}
		else
			inTree[i] = false;
	}
	prnt(inTree, graph, numEdge, cost);
	return 0;
}

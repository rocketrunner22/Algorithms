/*
#include <stdio.h>
#include <stdlib.h>

int max_num(int, int);
int knapsack(int);
node* create_node(int, int, node*);
node* add_to_list(node*, int, int);

struct node {
	int w;
	int val;
};


int main() {
	return 0;
}

node* create_node(int w, int val, node* next) {
	node*  new_node = (node*)malloc(sizeof(node));
	new_node->w = w;
	new_node->val = val;
	return new_node;
}

node *add_to_list(int w, int val, node *head) {
	if (head == NULL)
	{
		node *new_node;
		new_node = create_node(w, val, head);
		return head;
	}
	node *cursor = head;
	while (cursor->next != NULL)
		cursor = cursor->next;
	node *new_node = create_node(data, NULL);
	cursor->next = new_node;
	return head;
}

int knapsack(int W) {
	return 1;
}

int KnapSack(int i, int j) {
	int value;
	if (v[i][j] < 0) {
		if (j < w[i])
			value = KnapSack(i - 1, j);
		else
			value = max(KnapSack(i - 1, j), p[i] + KnapSack(i - 1, j - w[i]));
		v[i][j] = value;
	}
	return (v[i][j]);
}


int max_num(int x, int y) { return (x >= y) ? x : y; }
*/
/*/
#include<stdio.h>

#define N 6
int Weight[N];
int val[N];

int W = 10;
int item_count = 6;

int max(int a, int b) {
	return a >= b ? a : b;
}

int knapsack(int i, int W) {
	if (i == 0 || W == 0)
		return 0;

	if (Weight[i] >W)
		return knapsack(i - 1, W);
	else
		return max(knapsack(i - 1, W), knapsack(i - 1, W - Weight[i]) + val[i]);
}

int main() {

	Weight[0] = 6;
	Weight[1] = 1;
	Weight[2] = 2;
	Weight[3] = 5;
	Weight[4] = 4;
	Weight[5] = 3;

	val[0] = 10;
	val[1] = 5;
	val[2] = 7;
	val[3] = 12;
	val[4] = 8;
	val[5] = 6;

	printf("Max val: %d\n", knapsack(item_count, W));

	return 0;
}
*/
/*
#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>

namespace std {}
using namespace std;

struct item
{
	size_t value;
	size_t weight;
};

istream& operator>>(istream& is, item& i)
{
	return is >> i.value >> i.weight;
}

size_t knapsack_2d(vector<item>& store, const size_t capacity)
{
	const size_t n = store.size() + 1;
	const size_t W = capacity + 1;
	vector<vector<size_t> > T;
	T.resize(n);
	for (size_t i = 0; i < n; T[i].resize(W), ++i); /* This is our 2D managed array.

	for (size_t i = 0; i < W; T[0][i] = 0, ++i);

	for (size_t i = 0; i < store.size(); ++i)
	{
		for (size_t j = 0; j < W; ++j)
		{
			if (j >= store[i].weight)
			{
				T[i + 1][j] = max(T[i][j], T[i][j - store[i].weight] + store[i].value);
			}
			else
			{
				T[i + 1][j] = T[i][j];
			}
		}
	}

	size_t value = T[store.size()][capacity];

	return value;
}

size_t knapsack_1d(vector<item>& store, const size_t capacity)
{
	const size_t W = capacity + 1;
	vector<size_t> T;
	T.resize(W);

	for (size_t i = 0; i < W; T[i] = 0, ++i);

	for (size_t i = 0; i < store.size(); ++i)
	{
		int __w64 t = capacity - store[i].weight;
		if (t >= 0)
		{
			for (int __w64 j = t; j >= 0; --j)
			{
				T[j + store[i].weight] = max(T[j + store[i].weight], T[j] + store[i].value);
			}
		}
	}

	return T[capacity];
}

/*
int main(int argc, char* argv[])
{
	vector<item> store;
	size_t capacity = 0, count = 0;

	if (argc > 1)
	{
		ifstream ifs;
		ifs.open(argv[1]);

		ifs >> capacity >> count;

		item i = { 0 };
		while (ifs >> i)
		{
			store.push_back(i);
		}

		ifs.close();
	}

	cout << "Input size: " << store.size() << endl;
	assert(store.size() == count);

	size_t value = knapsack_1d(store, capacity);

	cout << "Optimal Value: " << value << endl;
	assert(value == 2595819);

	cin.get();

	return 0;
}

*/

#include <iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include <stdlib.h>
#include <iterator>
using namespace std;

void knapsack(int, int, vector< int >&, vector< int >&);


int main()
{
	ifstream input;
	input.open("knapsack.txt");
	if (input.fail())
	{
		cout << "Error opening file\n";
		exit(1);
	}

	int temp, num = 0, i = 0, knapsack_size, total_items;

	input >> knapsack_size;
	input >> total_items;

	vector< int > value(1);
	vector< int > weight(1);
	while (input >> temp)
	{
		value.push_back(temp);
		input >> temp;
		weight.push_back(temp);
	}
	/*for (int i = 0; i < value.size(); i++)
	{
		cout << value[i];
	}
	cout << endl;
	for (int i = 0; i < weight.size(); i++)
	{
		cout << weight[i];
	}
	cout << endl;*/
	knapsack(knapsack_size, total_items, value, weight);
}


void knapsack(int knapsack_size, int total_items, vector< int >&value, vector< int >&weight)
{
	vector< vector <int> > knapsack(total_items + 1, vector<int>(knapsack_size + 1));
	int i, w;

	//for (i = 0; i <= knapsack_size; i++)
		//knapsack[0][i] = 0;

	//for (i = 1; i <= total_items; i++) //columns to 0
		//knapsack[i][0] = 0;

	/*cout << endl;*/
	for (i = 1; i < knapsack.size(); i++)
		for (w = 0; w <= knapsack_size; w++)
		{
			if (weight[i] <= w) // item i can be part of the solution
			{
				if (value[i] + knapsack[i - 1][w - weight[i]] > knapsack[i - 1][w])
					knapsack[i][w] = value[i] + knapsack[i - 1][w - weight[i]];
				else
					knapsack[i][w] = knapsack[i - 1][w];
			}
			else
				knapsack[i][w] = knapsack[i - 1][w]; // wi > w

		}
	/*for (int i = 0; i < knapsack.size(); i++)
	{
		for (int j = 0; j < knapsack[i].size(); j++)
		{
			cout << knapsack[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;*/

	i = total_items;
	int k = knapsack_size, knapsack_max_value;
	vector <int> knapsack_item(0);
	while (i > 0 && k > 0)
	{
		if (knapsack[i][k] != knapsack[i - 1][k]) //then mark the ith item as in the knapsack
		{
			k = k - weight[i];
			knapsack_item.push_back(i);
			i = i - 1;
		}
		else
			i = i - 1;

	}
	/*for (int i = 0; i < knapsack_item.size(); i++)
	{
		cout << knapsack_item[i] << " ";
	}
	cout << endl;*/

	knapsack_max_value = knapsack[total_items][knapsack_size];

	cout << "\nMaximum knapsack value = " << knapsack_max_value << endl << endl;
	cout << "Item\tvalue weight\n";
	reverse(knapsack_item.begin(), knapsack_item.end());
	for (i = 0; i != knapsack_item.size(); i++)
		cout << knapsack_item[i] << "\t" << value[knapsack_item[i]] << " " << weight[knapsack_item[i]] << endl;

}
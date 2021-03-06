#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <array>
using namespace std;


void knapsack(vector<pair <int, int>>& items, int maxW, int numItems) {
	vector <vector <int>> table;

	for (int i = 0; i < numItems + 1; ++i)
		table.push_back(vector<int>(maxW + 1));

	for (int i = 0; i < table[0].size(); ++i)//first row == 0
		table[0][i] = 0;
	for (int i = 0; i < table.size(); ++i)//first col == 0
		table[i][0] = 0;

	for (int i = 1; i < table.size(); ++i)
		for (int w = 1; w < table[0].size(); w++) {
			if (items[i - 1].second <= w)
				table[i][w] = max(table[i - 1][w], items[i - 1].first + table[i - 1][w - items[i - 1].second]);
			else
				table[i][w] = table[i - 1][w];
		}

	cout << "Best Value: " << table[numItems][maxW] << endl << endl;
	cout << "Objects Used: (Value, Weight) " << endl;

	int w = maxW;

	//print objects to get
	for (int i = numItems; i > 0 && w > 0; i--) {
		if (table[i][w] == table[i - 1][w])
			continue;
		else {
			cout << items[i - 1].first << " " << items[i - 1].second << endl;
			w -= items[i - 1].second;
		}
	}
}


// first is val, second is weight
int main() {
	int maxW, numItems;

	cout << "Enter Max Weight and Number of objects: ";
	cin >> maxW;
	cin >> numItems;

	vector <pair<int, int>> items;
	for (int i = 0; i < numItems; ++i) {
		cout << "Enter Value then weight: ";
		pair<int, int> p;
		cin >> p.first >> p.second;
		items.emplace_back(p);
	}

	sort(items.begin(), items.end(), [](auto p1, auto p2) {/*return double(p1.first) / p1.second > double(p2.first) / p2.second;*/
		return double(p1.second) < double(p2.second); });
	knapsack(items, maxW, numItems);

	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

struct Item {
	int weight;
	int value;
};

int knapsackCombinatorial(int capacity, const vector<Item>& items, int idx, int currentWeight, int currentValue) {
	if (idx == items.size() || currentWeight >= capacity) {
		return currentValue;
	}
	
	// Incluir el elemento actual
	int withCurrent = 0;
	if (currentWeight + items[idx].weight <= capacity) {
		withCurrent = knapsackCombinatorial(capacity, items, idx + 1, currentWeight + items[idx].weight, currentValue + items[idx].value);
	}
	
	// No incluir el elemento actual
	int withoutCurrent = knapsackCombinatorial(capacity, items, idx + 1, currentWeight, currentValue);
	
	return max(withCurrent, withoutCurrent);
}

int main() {
	int capacity = 10;
	vector<Item> items = {{2, 5}, {3, 8}, {4, 9}, {5, 10}};
	
	int maxValue = knapsackCombinatorial(capacity, items, 0, 0, 0);
	cout << "Maximo valor usando Arbol Combinarotio: " << maxValue << endl;
	
	return 0;
}



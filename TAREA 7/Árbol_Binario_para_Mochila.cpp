#include <iostream>
#include <vector>

using namespace std;

struct Item {
	int weight;
	int value;
};

int knapsackBinary(int capacity, const vector<Item>& items, int idx, int currentWeight, int currentValue) {
	if (currentWeight > capacity || idx == items.size()) {
		return 0;
	}
	
	// Incluir el elemento actual
	int withCurrent = items[idx].value + knapsackBinary(capacity, items, idx + 1, currentWeight + items[idx].weight, currentValue + items[idx].value);
	
	// No incluir el elemento actual
	int withoutCurrent = knapsackBinary(capacity, items, idx + 1, currentWeight, currentValue);
	
	return max(withCurrent, withoutCurrent);
}

int main() {
	int capacity = 10;
	vector<Item> items = {{2, 5}, {3, 8}, {4, 9}, {5, 10}};
	
	int maxValue = knapsackBinary(capacity, items, 0, 0, 0);
	cout << "Maximo valor usando Arbol Binario: " << maxValue << endl;
	
	return 0;
}


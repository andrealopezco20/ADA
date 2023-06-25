#include <iostream>
#include <vector>

// Funci�n para intercambiar dos elementos en un vector
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

// Funci�n para colocar el pivote en su posici�n correcta en el vector
int partition(std::vector<int>& arr, int low, int high) {
	int pivot = arr[high];    // Seleccionar el �ltimo elemento como pivote
	int i = low - 1;          // �ndice del elemento m�s peque�o
	
	for (int j = low; j < high; j++) {
		// Si el elemento actual es m�s peque�o o igual que el pivote
		if (arr[j] <= pivot) {
			i++;  // Incrementar el �ndice del elemento m�s peque�o
			swap(arr[i], arr[j]);  // Intercambiar elementos
		}
	}
	
	swap(arr[i + 1], arr[high]);  // Colocar el pivote en su posici�n correcta
	return i + 1;  // Retornar la posici�n del pivote
}

// Funci�n principal del algoritmo Quick Sort
void quickSort(std::vector<int>& arr, int low, int high) {
	if (low < high) {
		int pivotIndex = partition(arr, low, high);  // Obtener la posici�n del pivote
		
		// Ordenar recursivamente los elementos antes y despu�s del pivote
		quickSort(arr, low, pivotIndex - 1);
		quickSort(arr, pivotIndex + 1, high);
	}
}

int main() {
	std::vector<int> arr = {1, 7, 2, 3, 4, 6};
	
	std::cout << "Array original: ";
	for (const auto& num : arr)
		std::cout << num << " ";
	std::cout << std::endl;
	
	quickSort(arr, 0, arr.size() - 1);
	
	std::cout << "Array ordenado: ";
	for (const auto& num : arr)
		std::cout << num << " ";
	std::cout << std::endl;
	
	return 0;
}

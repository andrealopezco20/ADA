#include <iostream>
#include <vector>

// Función de búsqueda binaria
int binarySearch(const std::vector<int>& arr, int target) {
	int low = 0;
	int high = arr.size() - 1;
	
	while (low <= high) {
		int mid = low + (high - low) / 2;
		
		if (arr[mid] == target) {
			return mid;  // Se encontró el elemento, se devuelve su índice
		} else if (arr[mid] < target) {
			low = mid + 1;  // El elemento buscado está en la mitad derecha del subarreglo
		} else {
			high = mid - 1;  // El elemento buscado está en la mitad izquierda del subarreglo
		}
	}
	
	return -1;  // El elemento no se encuentra en el arreglo
}

int main() {
	std::vector<int> arr = {2, 5, 7, 10, 15, 20, 25, 30};
	int target = 10;
	
	int index = binarySearch(arr, target);
	
	if (index != -1) {
		std::cout << "El elemento " << target << " se encuentra en el índice " << index << std::endl;
	} else {
		std::cout << "El elemento " << target << " no se encuentra en el arreglo" << std::endl;
	}
	
	return 0;
}

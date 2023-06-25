#include <iostream>
#include <vector>

// Función para combinar dos subvectores ordenados
void merge(std::vector<int>& arr, int left, int mid, int right) {
	int n1 = mid - left + 1;    // Tamaño del subvector izquierdo
	int n2 = right - mid;       // Tamaño del subvector derecho
	
	// Crear subvectores temporales
	std::vector<int> L(n1), R(n2);
	
	// Copiar datos a los subvectores temporales
	for (int i = 0; i < n1; i++)
		L[i] = arr[left + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[mid + 1 + j];
	
	// Combinar los subvectores temporales en uno ordenado
	int i = 0;     // Índice del subvector izquierdo
	int j = 0;     // Índice del subvector derecho
	int k = left;  // Índice del subvector combinado
	
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		} else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	
	// Copiar los elementos restantes del subvector izquierdo, si los hay
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	
	// Copiar los elementos restantes del subvector derecho, si los hay
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

// Función principal del algoritmo Merge Sort
void mergeSort(std::vector<int>& arr, int left, int right) {
	if (left < right) {
		// Calcular el punto medio
		int mid = left + (right - left) / 2;
		
		// Ordenar recursivamente los subvectores izquierdo y derecho
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		
		// Combinar los subvectores ordenados
		merge(arr, left, mid, right);
	}
}

int main() {
	std::vector<int> arr = {10, 7, 8, 3, 1, 2};
	
	std::cout << "Array original: ";
	for (const auto& num : arr)
		std::cout << num << " ";
	std::cout << std::endl;
	
	mergeSort(arr, 0, arr.size() - 1);
	
	std::cout << "Array ordenado: ";
	for (const auto& num : arr)
		std::cout << num << " ";
	std::cout << std::endl;
	
	return 0;
}

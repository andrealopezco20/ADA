#include <iostream>
#include <vector>

// Función para sumar dos matrices
std::vector<std::vector<int>> sumMatrix(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
	int n = A.size();
	int m = A[0].size();
	std::vector<std::vector<int>> C(n, std::vector<int>(m));
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			C[i][j] = A[i][j] + B[i][j];
		}
	}
	
	return C;
}

// Función para restar dos matrices
std::vector<std::vector<int>> subtractMatrix(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
	int n = A.size();
	int m = A[0].size();
	std::vector<std::vector<int>> C(n, std::vector<int>(m));
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			C[i][j] = A[i][j] - B[i][j];
		}
	}
	
	return C;
}

// Función para multiplicar dos matrices usando el algoritmo de Strassen
std::vector<std::vector<int>> strassenMatrixMultiply(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
	int n = A.size();
	
	// Caso base: matrices de 1x1
	if (n == 1) {
		std::vector<std::vector<int>> C(1, std::vector<int>(1));
		C[0][0] = A[0][0] * B[0][0];
		return C;
	}
	
	// Dividir las matrices en submatrices
	int mid = n / 2;
	std::vector<std::vector<int>> A11(mid, std::vector<int>(mid));
	std::vector<std::vector<int>> A12(mid, std::vector<int>(mid));
	std::vector<std::vector<int>> A21(mid, std::vector<int>(mid));
	std::vector<std::vector<int>> A22(mid, std::vector<int>(mid));
	
	std::vector<std::vector<int>> B11(mid, std::vector<int>(mid));
	std::vector<std::vector<int>> B12(mid, std::vector<int>(mid));
	std::vector<std::vector<int>> B21(mid, std::vector<int>(mid));
	std::vector<std::vector<int>> B22(mid, std::vector<int>(mid));
	
	for (int i = 0; i < mid; i++) {
		for (int j = 0; j < mid; j++) {
			A11[i][j] = A[i][j];
			A12[i][j] = A[i][j + mid];
			A21[i][j] = A[i + mid][j];
			A22[i][j] = A[i + mid][j + mid];
			
			B11[i][j] = B[i][j];
			B12[i][j] = B[i][j + mid];
			B21[i][j] = B[i + mid][j];
			B22[i][j] = B[i + mid][j + mid];
		}
	}
	
	// Calcular las submatrices necesarias para el algoritmo de Strassen
	std::vector<std::vector<int>> P1 = strassenMatrixMultiply(A11, subtractMatrix(B12, B22));
	std::vector<std::vector<int>> P2 = strassenMatrixMultiply(sumMatrix(A11, A12), B22);
	std::vector<std::vector<int>> P3 = strassenMatrixMultiply(sumMatrix(A21, A22), B11);
	std::vector<std::vector<int>> P4 = strassenMatrixMultiply(A22, subtractMatrix(B21, B11));
	std::vector<std::vector<int>> P5 = strassenMatrixMultiply(sumMatrix(A11, A22), sumMatrix(B11, B22));
	std::vector<std::vector<int>> P6 = strassenMatrixMultiply(subtractMatrix(A12, A22), sumMatrix(B21, B22));
	std::vector<std::vector<int>> P7 = strassenMatrixMultiply(subtractMatrix(A11, A21), sumMatrix(B11, B12));
	
	// Calcular las submatrices del resultado final
	std::vector<std::vector<int>> C11 = subtractMatrix(sumMatrix(sumMatrix(P5, P4), P6), P2);
	std::vector<std::vector<int>> C12 = sumMatrix(P1, P2);
	std::vector<std::vector<int>> C21 = sumMatrix(P3, P4);
	std::vector<std::vector<int>> C22 = subtractMatrix(subtractMatrix(sumMatrix(P5, P1), P3), P7);
	
	// Combinar las submatrices para obtener la matriz resultante
	std::vector<std::vector<int>> C(n, std::vector<int>(n));
	for (int i = 0; i < mid; i++) {
		for (int j = 0; j < mid; j++) {
			C[i][j] = C11[i][j];
			C[i][j + mid] = C12[i][j];
			C[i + mid][j] = C21[i][j];
			C[i + mid][j + mid] = C22[i][j];
		}
	}
	
	return C;
}

// Función para imprimir una matriz
void printMatrix(const std::vector<std::vector<int>>& matrix) {
	for (const auto& row : matrix) {
		for (const auto& elem : row) {
			std::cout << elem << " ";
		}
		std::cout << std::endl;
	}
}

int main() {
	std::vector<std::vector<int>> A = {{1, 2, 3, 4},
	{5, 6, 7, 8},
	{9, 10, 11, 12},
	{13, 14, 15, 16}};
	
	std::vector<std::vector<int>> B = {{17, 18, 19, 20},
	{21, 22, 23, 24},
	{25, 26, 27, 28},
	{29, 30, 31, 32}};
	
	std::cout << "Matriz A:" << std::endl;
	printMatrix(A);
	
	std::cout << "\nMatriz B:" << std::endl;
	printMatrix(B);
	
	std::cout << "\nResultado de la multiplicacion de matrices usando Strassen:" << std::endl;
	std::vector<std::vector<int>> C = strassenMatrixMultiply(A, B);
	printMatrix(C);
	
	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>


/*
La solución al problema de la mochila mediante programación dinámica se basa en la idea de que es posible construir una tabla de 
valores óptimos para subproblemas más pequeños, y utilizar esta información para resolver el problema completo.

El algoritmo de programación dinámica para el problema de la mochila se puede describir de la siguiente manera:

Crear una tabla de tamaño (n+1) x (W+1), donde n es el número de objetos y W es la capacidad de la mochila.
Inicializar la primera fila y la primera columna de la tabla con ceros.
Para cada objeto i desde 1 hasta n, y para cada capacidad j desde 1 hasta W:
a. Si el peso del objeto i es mayor que la capacidad j, entonces el valor óptimo para este subproblema es 
el mismo que el valor óptimo para el subproblema con los objetos i-1 y la capacidad j.
b. Si el peso del objeto i es menor o igual que la capacidad j, entonces el valor óptimo para este subproblema 
es el máximo entre el valor óptimo para el subproblema con los objetos i-1 y la capacidad j, 
y el valor del objeto i más el valor óptimo para el subproblema con los objetos i-1 y la capacidad j menos el peso del objeto i.
El valor óptimo para el problema completo es el valor almacenado en la celda (n,W) de la tabla.
*/
using namespace std;

int knapsack(int W, vector<int>& wt, vector<int>& val, int n) {
	vector<vector<int>> K(n+1, vector<int>(W+1));
	
	for (int i = 0; i <= n; i++) {
		for (int w = 0; w <= W; w++) {
			if (i == 0 || w == 0)
				K[i][w] = 0;
			else if (wt[i-1] <= w)
				K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]);
			else
				K[i][w] = K[i-1][w];
		}
	}
	
	return K[n][W];
}

int main() {
	int W = 50; // Capacidad de la mochila
	vector<int> wt = {10, 20, 30}; // Pesos de los objetos
	vector<int> val = {60, 100, 120}; // Valores de los objetos
	int n = wt.size();
	
	int max_val = knapsack(W, wt, val, n);
	
	cout << "Valor máximo obtenido: " << max_val << endl;
	
	return 0;
}


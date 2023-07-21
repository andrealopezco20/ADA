#include <iostream>
#include <vector>
#include <climits>

/*La solución al problema del cambio de monedas mediante programación dinámica se basa en la idea de que es posible 
construir una tabla de valores óptimos para subproblemas más pequeños, 
y utilizar esta información para resolver el problema completo.
El algoritmo de programación dinámica para el problema del cambio de monedas se puede describir de la siguiente manera:

Crear una tabla de tamaño (n+1) x (S+1), donde n es el número de tipos de monedas y S es la cantidad de dinero a sumar.
Inicializar la primera fila de la tabla con infinito y la primera columna de la tabla con ceros.
Para cada tipo de moneda i desde 1 hasta n, y para cada cantidad de dinero j desde 1 hasta S:
a. Si el valor de la moneda i es mayor que la cantidad de dinero j, entonces el número mínimo de 
monedas para sumar la cantidad j utilizando las primeras i monedas es el mismo que el número mínimo de monedas 
para sumar la cantidad j utilizando las primeras i-1 monedas.
b. Si el valor de la moneda i es menor o igual que la cantidad de dinero j, entonces el número mínimo de monedas 
para sumar la cantidad j utilizando las primeras i monedas es el mínimo entre el número mínimo de monedas para sumar la cantidad j 
utilizando las primeras i-1 monedas, y el número mínimo de monedas para sumar la cantidad j-valor_i utilizando 
las primeras i monedas más una moneda adicional de valor_i.
El número mínimo de monedas para sumar la cantidad S utilizando todas las monedas es el valor almacenado en la celda (n,S) de la tabla.
*/


using namespace std;

int coinChange(vector<int>& coins, int amount) {
	int n = coins.size();
	vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INT_MAX));
	
	// Inicialización de la primera columna
	for (int i = 0; i <= n; i++) {
		dp[i][0] = 0;
	}
	
	// Inicialización de la primera fila
	for (int j = 1; j <= amount; j++) {
		dp[0][j] = INT_MAX;
	}
	
	// Llenado de la tabla
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= amount; j++) {
			if (coins[i - 1] <= j) {
				int withoutCoin = dp[i - 1][j];
				int withCoin = dp[i][j - coins[i - 1]];
				if (withCoin != INT_MAX) {
					withCoin++;
				}
				dp[i][j] = min(withoutCoin, withCoin);
			} else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	
	// Resultado
	if (dp[n][amount] == INT_MAX) {
		return -1;
	} else {
		return dp[n][amount];
	}
}

int main() {
	vector<int> coins = {1, 2, 5}; // Valores de las monedas
	int amount = 11; // Cantidad de dinero a sumar
	
	int minCoins = coinChange(coins, amount);
	
	if (minCoins == -1) {
		cout << "No es posible sumar la cantidad deseada." << endl;
	} else {
		cout << "La cantidad mínima de monedas necesaria es: " << minCoins << endl;
	}
	
	return 0;
}

#include <iostream>
#include <vector>
#include <climits>

/*La soluci�n al problema del cambio de monedas mediante programaci�n din�mica se basa en la idea de que es posible 
construir una tabla de valores �ptimos para subproblemas m�s peque�os, 
y utilizar esta informaci�n para resolver el problema completo.
El algoritmo de programaci�n din�mica para el problema del cambio de monedas se puede describir de la siguiente manera:

Crear una tabla de tama�o (n+1) x (S+1), donde n es el n�mero de tipos de monedas y S es la cantidad de dinero a sumar.
Inicializar la primera fila de la tabla con infinito y la primera columna de la tabla con ceros.
Para cada tipo de moneda i desde 1 hasta n, y para cada cantidad de dinero j desde 1 hasta S:
a. Si el valor de la moneda i es mayor que la cantidad de dinero j, entonces el n�mero m�nimo de 
monedas para sumar la cantidad j utilizando las primeras i monedas es el mismo que el n�mero m�nimo de monedas 
para sumar la cantidad j utilizando las primeras i-1 monedas.
b. Si el valor de la moneda i es menor o igual que la cantidad de dinero j, entonces el n�mero m�nimo de monedas 
para sumar la cantidad j utilizando las primeras i monedas es el m�nimo entre el n�mero m�nimo de monedas para sumar la cantidad j 
utilizando las primeras i-1 monedas, y el n�mero m�nimo de monedas para sumar la cantidad j-valor_i utilizando 
las primeras i monedas m�s una moneda adicional de valor_i.
El n�mero m�nimo de monedas para sumar la cantidad S utilizando todas las monedas es el valor almacenado en la celda (n,S) de la tabla.
*/


using namespace std;

int coinChange(vector<int>& coins, int amount) {
	int n = coins.size();
	vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INT_MAX));
	
	// Inicializaci�n de la primera columna
	for (int i = 0; i <= n; i++) {
		dp[i][0] = 0;
	}
	
	// Inicializaci�n de la primera fila
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
		cout << "La cantidad m�nima de monedas necesaria es: " << minCoins << endl;
	}
	
	return 0;
}

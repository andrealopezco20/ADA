#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Objeto {
	int peso;
	int valor;
};

bool compararPorValor(Objeto o1, Objeto o2) {
	return o1.valor > o2.valor;
}

int problemaMochila(vector<Objeto> objetos, int capacidad) {
	sort(objetos.begin(), objetos.end(), compararPorValor);
	
	vector<int> dp(capacidad + 1, 0);
	
	for (int i = 0; i < objetos.size(); i++) {
		for (int j = capacidad; j >= objetos[i].peso; j--) {
			dp[j] = max(dp[j], dp[j - objetos[i].peso] + objetos[i].valor);
		}
	}
	
	return dp[capacidad];
}

int main() {
	vector<Objeto> objetos = {{1, 12}, {4, 6}, {3, 5}, {2, 3}, {1, 2}, {7, 18}, {2, 3}};
	int capacidadMochila = 15;
	
	int maximoValorMochila = problemaMochila(objetos, capacidadMochila);
	
	cout << "El valor máximo en la mochila es: " << maximoValorMochila << endl;
	
	return 0;
}

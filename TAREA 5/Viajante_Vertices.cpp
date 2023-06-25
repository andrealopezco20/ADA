#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Punto {
	int x, y;
	Punto(int x = 0, int y = 0): x(x), y(y) {}
};

double distancia(Punto a, Punto b) {
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

double calcularDistanciaRecorrido(const vector<Punto>& puntos, const vector<int>& recorrido) {
	double distanciaTotal = 0.0;
	int n = recorrido.size();
	for (int i = 0; i < n - 1; i++) {
		int puntoActual = recorrido[i];
		int puntoSiguiente = recorrido[i + 1];
		distanciaTotal += distancia(puntos[puntoActual], puntos[puntoSiguiente]);
	}
	// Agregar la distancia desde el último punto al primero (cierre del ciclo)
	distanciaTotal += distancia(puntos[recorrido[n - 1]], puntos[recorrido[0]]);
	return distanciaTotal;
}

vector<int> generarPermutacionInicial(int n) {
	vector<int> permutacion;
	for (int i = 0; i < n; i++) {
		permutacion.push_back(i);
	}
	return permutacion;
}

void buscarMejorRecorrido(const vector<Punto>& puntos, vector<int>& recorridoActual, double& distanciaMinima) {
	int n = recorridoActual.size();
	if (n == puntos.size()) {
		double distanciaActual = calcularDistanciaRecorrido(puntos, recorridoActual);
		if (distanciaActual < distanciaMinima) {
			distanciaMinima = distanciaActual;
		}
	} else {
		for (int i = n; i < puntos.size(); i++) {
			swap(recorridoActual[n], recorridoActual[i]);
			buscarMejorRecorrido(puntos, recorridoActual, distanciaMinima);
			swap(recorridoActual[n], recorridoActual[i]); // Deshacer el intercambio (backtracking)
		}
	}
}

vector<int> encontrarMejorRecorrido(const vector<Punto>& puntos) {
	int n = puntos.size();
	vector<int> permutacionInicial = generarPermutacionInicial(n);
	double distanciaMinima = numeric_limits<double>::max();
	vector<int> mejorRecorrido;
	do {
		double distanciaActual = calcularDistanciaRecorrido(puntos, permutacionInicial);
		if (distanciaActual < distanciaMinima) {
			distanciaMinima = distanciaActual;
			mejorRecorrido = permutacionInicial;
		}
	} while (next_permutation(permutacionInicial.begin(), permutacionInicial.end()));
	return mejorRecorrido;
}

int main() {
	cout << "Ingrese el número de puntos y las coordenadas de cada punto:" << endl;
	int n;
	cin >> n;
	vector<Punto> puntos(n);
	cout << "Ingrese las coordenadas de cada punto:" << endl;
	for (int i = 0; i < n; i++)
		cin >> puntos[i].x >> puntos[i].y;
	vector<int> mejorRecorrido = encontrarMejorRecorrido(puntos);
	cout << "Mejor recorrido encontrado:" << endl;
	for (int i = 0; i < n; i++)
		cout << mejorRecorrido[i] << ' ';
	cout << endl;
	return 0;
}

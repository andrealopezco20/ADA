#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
using namespace std;

struct Ciudad {
	int id;
	double x;
	double y;
};

double calcularDistancia(const Ciudad& ciudad1, const Ciudad& ciudad2) {
	double dx = ciudad1.x - ciudad2.x;
	double dy = ciudad1.y - ciudad2.y;
	return sqrt(dx*dx + dy*dy);
}

vector<int> tspVecinoMasCercano(const vector<Ciudad>& ciudades, int ciudadInicio) {
	int numCiudades = ciudades.size();
	vector<int> recorrido;
	vector<bool> visitado(numCiudades, false);
	
	recorrido.push_back(ciudadInicio);
	visitado[ciudadInicio] = true;
	
	for (int i = 1; i < numCiudades; i++) {
		int ciudadActual = recorrido.back();
		double distanciaMinima = numeric_limits<double>::max();
		int siguienteCiudad = -1;
		
		for (int j = 0; j < numCiudades; j++) {
			if (!visitado[j]) {
				double distancia = calcularDistancia(ciudades[ciudadActual], ciudades[j]);
				if (distancia < distanciaMinima) {
					distanciaMinima = distancia;
					siguienteCiudad = j;
				}
			}
		}
		
		recorrido.push_back(siguienteCiudad);
		visitado[siguienteCiudad] = true;
	}
	
	return recorrido;
}

int main() {
	int numCiudades;
	cout << "Ingrese el número de ciudades: ";
	cin >> numCiudades;
	
	vector<Ciudad> ciudades(numCiudades);
	
	for (int i = 0; i < numCiudades; i++) {
		cout << "Ingrese las coordenadas (x, y) de la ciudad " << i << ": ";
		cin >> ciudades[i].x >> ciudades[i].y;
		ciudades[i].id = i;
	}
	
	int ciudadInicio;
	cout << "Ingrese el ID de la ciudad de inicio: ";
	cin >> ciudadInicio;
	
	vector<int> recorrido = tspVecinoMasCercano(ciudades, ciudadInicio);
	
	cout << "Recorrido: ";
	for (int i = 0; i < recorrido.size(); i++) {
		cout << recorrido[i];
		if (i != recorrido.size() - 1)
			cout << " -> ";
	}
	cout << endl;
	
	return 0;
}


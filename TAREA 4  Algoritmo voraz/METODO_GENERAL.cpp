#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> ConjuntoCandidatos;
typedef vector<int> ConjuntoSolucion;

int seleccionar(const ConjuntoCandidatos& C) {
	int minElement = C[0];
	for (int i = 1; i < C.size(); i++) {
		if (C[i] < minElement) {
			minElement = C[i];
		}
	}
	return minElement;
}

bool factible(const ConjuntoSolucion& S, int x) {
	
	// Por ejemplo, supongamos que la factibilidad depende de que la suma
	// de los elementos en la solución más el candidato x sea menor o igual a 10:
	int sum = x;
	for (int i = 0; i < S.size(); i++) {
		sum += S[i];
	}
	return sum <= 10;
}

void insertar(ConjuntoSolucion& S, int x) {
	
	S.push_back(x);
}

bool solucion(const ConjuntoSolucion& S) {
	
	// Por ejemplo, supongamos que una solución válida debe tener una cantidad mínima de elementos:
	return S.size() >= 3;
}

void voraz(const ConjuntoCandidatos& C, ConjuntoSolucion& S) {
	S.clear();
	ConjuntoCandidatos candidatosRestantes = C;
	
	while (!candidatosRestantes.empty() && !solucion(S)) {
		int x = seleccionar(candidatosRestantes);
		candidatosRestantes.erase(std::remove(candidatosRestantes.begin(), candidatosRestantes.end(), x), candidatosRestantes.end());
		
		if (factible(S, x)) {
			insertar(S, x);
		}
	}
	
	if (!solucion(S)) {
		cout << "No se puede encontrar solución" << endl;
	}
}

int main() {
	ConjuntoCandidatos candidatos = {4, 7, 2, 1, 9, 5, 3};
	ConjuntoSolucion solucionFinal;
	
	voraz(candidatos, solucionFinal);
	
	if (solucion(solucionFinal)) {
		cout << "Solución encontrada: ";
		for (int i = 0; i < solucionFinal.size(); i++) {
			cout << solucionFinal[i] << " ";
		}
		cout << endl;
	}
	
	return 0;
}


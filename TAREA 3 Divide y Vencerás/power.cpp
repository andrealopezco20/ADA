#include <iostream>
using namespace std;
// Función para calcular la potencia de un número
double power(double base, int exponente) {
	if (exponente == 0) {
		return 1.0;  // Cualquier número elevado a 0 es igual a 1
	}
	
	double resultado = 1.0;
	int absExponente = abs(exponente);  // Valor absoluto del exponente
	
	for (int i = 0; i < absExponente; i++) {
		resultado *= base;
	}
	
	if (exponente < 0) {
		return 1.0 / resultado;  // Si el exponente es negativo, se devuelve el inverso del resultado
	}
	
	return resultado;
}

int main() {
	double base;
	int exponente;
	
	cout << "Ingrese la base: ";
	cin >> base;
	
	cout << "Ingrese el exponente: ";
	cin >> exponente;
	
	double resultado = power(base, exponente);
	
	cout << "El resultado es "<< resultado << endl;
	
	return 0;
}

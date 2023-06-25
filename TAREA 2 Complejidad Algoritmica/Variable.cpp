//transformación de una variable o conjunto de variables en un algoritmo para facilitar su manipulación y resolución de un problema específico.
#include <iostream>
using namespace std;
int CambioVariable(int n){
	if (n == 0){
		return 1;
	}
	else {
		int m = n - 1;
		return CambioVariable(m) + 2;
	}
}

int main(){
	int x = 4;
	int respuesta = CambioVariable(x);
	cout << respuesta << endl;
	
	return 0;
}
